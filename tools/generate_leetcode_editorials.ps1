param(
    [int]$Start = 5,
    [int]$End = 20,
    [string]$EditorialRoot = "editorial"
)

$ErrorActionPreference = "Stop"

$repoRoot = (Resolve-Path ".").Path
$editorialRootPath = Join-Path $repoRoot $EditorialRoot
if (-not (Test-Path $editorialRootPath)) {
    New-Item -ItemType Directory -Path $editorialRootPath | Out-Null
}
$editorialRootPath = (Resolve-Path $editorialRootPath).Path

$langs = @(
    @{ Slug = "c"; Folder = "C"; Ext = "c"; Label = "C"; Fence = "c" },
    @{ Slug = "cpp"; Folder = "CPP"; Ext = "cpp"; Label = "C++"; Fence = "cpp" },
    @{ Slug = "csharp"; Folder = "CSharp"; Ext = "cs"; Label = "C#"; Fence = "csharp" },
    @{ Slug = "golang"; Folder = "Go"; Ext = "go"; Label = "Go"; Fence = "go" },
    @{ Slug = "java"; Folder = "Java"; Ext = "java"; Label = "Java"; Fence = "java" },
    @{ Slug = "javascript"; Folder = "JavaScript"; Ext = "js"; Label = "JavaScript"; Fence = "javascript" },
    @{ Slug = "python"; Folder = "Python"; Ext = "py"; Label = "Python"; Fence = "python" },
    @{ Slug = "python3"; Folder = "Python3"; Ext = "py"; Label = "Python3"; Fence = "python" },
    @{ Slug = "typescript"; Folder = "TypeScript"; Ext = "ts"; Label = "TypeScript"; Fence = "typescript" }
)

function Write-Utf8NoBom($Path, $Content) {
    $encoding = [System.Text.UTF8Encoding]::new($false)
    [System.IO.File]::WriteAllText($Path, $Content, $encoding)
}

function Convert-ToFolderName($QuestionId, $Title) {
    $name = $Title -replace "[^A-Za-z0-9]+", "_"
    $name = $name.Trim("_")
    return "$QuestionId`_$name"
}

function Convert-ToFileBase($Index, $Heading) {
    $name = $Heading -replace "^Approach\s+\d+:\s*", ""
    $name = $name -replace "\(.*?\)", ""
    $name = $name -replace "[^A-Za-z0-9]+", "_"
    $name = $name.Trim("_")
    if (-not $name) { $name = "Approach_$Index" }
    return "$Index`_$name"
}

function Convert-DifficultyBadge($Difficulty) {
    switch ($Difficulty) {
        "Easy" { return "![Easy](../../Miscellaneous/Badges/Easy.svg)" }
        "Medium" { return "![Medium](../../Miscellaneous/Badges/Med.svg)" }
        "Hard" { return "![Hard](../../Miscellaneous/Badges/Hard.svg)" }
        default { return $Difficulty }
    }
}

function Convert-TopBadge($Difficulty, $Url) {
    switch ($Difficulty) {
        "Easy" { return "[![Easy](../../Miscellaneous/Badges/Easy.svg)]($Url)" }
        "Medium" { return "[![Medium](../../Miscellaneous/Badges/Med.svg)]($Url)" }
        "Hard" { return "[![Hard](../../Miscellaneous/Badges/Hard.svg)]($Url)" }
        default { return "[$Difficulty]($Url)" }
    }
}

function Get-CodeForLang($CodesByUuid, $Uuid, $Slug) {
    $entries = $CodesByUuid.$Uuid
    $entry = $entries | Where-Object { $_.langSlug -eq $Slug } | Select-Object -First 1
    if (-not $entry) {
        return $null
    }
    return ($entry.code -replace "`r`n", "`n").TrimEnd()
}

function Convert-InlineCodeMeta($InlineCode, $FallbackIndex) {
    $labelHint = [string]$InlineCode.label
    $langHint = [string]$InlineCode.langHint
    $code = [string]$InlineCode.code
    $source = ("$labelHint $langHint $code").ToLowerInvariant()

    if ($source -match "ms\s*sql|sql\s*server|mssql") {
        return @{ Key = "mssql"; Folder = "MSSQL"; Ext = "sql"; Label = "MS SQL Server"; Fence = "sql" }
    }
    if ($source -match "mysql") {
        return @{ Key = "mysql"; Folder = "MySQL"; Ext = "sql"; Label = "MySQL"; Fence = "sql" }
    }
    if ($source -match "oracle") {
        return @{ Key = "oracle"; Folder = "Oracle"; Ext = "sql"; Label = "Oracle"; Fence = "sql" }
    }
    if ($source -match "postgres|postgresql") {
        return @{ Key = "postgresql"; Folder = "PostgreSQL"; Ext = "sql"; Label = "PostgreSQL"; Fence = "sql" }
    }
    if ($source -match "pandas|pd\.dataframe|dataframe") {
        return @{ Key = "pandas"; Folder = "Pandas"; Ext = "py"; Label = "Pandas"; Fence = "python" }
    }
    if ($source -match "python") {
        return @{ Key = "python3"; Folder = "Python3"; Ext = "py"; Label = "Python3"; Fence = "python" }
    }
    if ($source -match "bash|shell|awk|sed|grep") {
        return @{ Key = "bash"; Folder = "Bash"; Ext = "sh"; Label = "Bash"; Fence = "bash" }
    }
    if ($source -match "\bselect\b|\bfrom\b|\bwhere\b|\bjoin\b|\bupdate\b|\bdelete\b|\bwith\b") {
        return @{ Key = "sql_$FallbackIndex"; Folder = "SQL"; Ext = "sql"; Label = "SQL"; Fence = "sql" }
    }

    return $null
}

function Convert-PlaygroundCodeMeta($Lang, $Code) {
    if ($Lang.Slug -eq "python" -and ([string]$Code).ToLowerInvariant() -match "pandas|pd\.dataframe|dataframe") {
        return @{ Key = "pandas"; Folder = "Pandas"; Ext = "py"; Label = "Pandas"; Fence = "python" }
    }

    return @{
        Key = $Lang.Slug
        Folder = $Lang.Folder
        Ext = $Lang.Ext
        Label = $Lang.Label
        Fence = $Lang.Fence
    }
}

function Get-ApproachCodeEntries($Item, $Approach) {
    $entries = @()
    foreach ($lang in $langs) {
        $code = Get-CodeForLang $Item.codesByUuid $Approach.uuid $lang.Slug
        if ($null -eq $code) {
            continue
        }
        $meta = Convert-PlaygroundCodeMeta $lang $code
        $entries += [pscustomobject]@{
            Key = $meta.Key
            Folder = $meta.Folder
            Ext = $meta.Ext
            Label = $meta.Label
            Fence = $meta.Fence
            Code = $code
        }
    }

    if ($entries.Count -gt 0 -or -not $Approach.inlineCodes) {
        return $entries
    }

    $index = 0
    foreach ($inlineCode in $Approach.inlineCodes) {
        $index++
        $code = ([string]$inlineCode.code -replace "`r`n", "`n").TrimEnd()
        if (-not $code) {
            continue
        }
        $meta = Convert-InlineCodeMeta $inlineCode $index
        if ($null -eq $meta) {
            continue
        }
        $entries += [pscustomobject]@{
            Key = $meta.Key
            Folder = $meta.Folder
            Ext = $meta.Ext
            Label = $meta.Label
            Fence = $meta.Fence
            Code = $code
        }
    }

    return $entries
}

$tabs = (Invoke-WebRequest -Uri "http://127.0.0.1:9222/json" -UseBasicParsing -TimeoutSec 5).Content | ConvertFrom-Json
$tabInfo = $tabs | Where-Object { $_.type -eq "page" -and $_.url -like "https://leetcode.com*" } | Select-Object -First 1
if (-not $tabInfo) {
    throw "No LeetCode page tab found on Chrome debugging port 9222."
}

$ws = [System.Net.WebSockets.ClientWebSocket]::new()
$ct = [Threading.CancellationToken]::None
$ws.ConnectAsync([Uri]$tabInfo.webSocketDebuggerUrl, $ct).GetAwaiter().GetResult()
$script:cdpId = 0

function Send-Cdp($Method, $Params) {
    $script:cdpId++
    $payload = @{ id = $script:cdpId; method = $Method }
    if ($null -ne $Params) {
        $payload.params = $Params
    }
    $json = $payload | ConvertTo-Json -Depth 100 -Compress
    $bytes = [Text.Encoding]::UTF8.GetBytes($json)
    $script:ws.SendAsync([ArraySegment[byte]]::new($bytes), [System.Net.WebSockets.WebSocketMessageType]::Text, $true, $script:ct).GetAwaiter().GetResult()
    while ($true) {
        $chunks = [System.Text.StringBuilder]::new()
        do {
            $buffer = New-Object byte[] 1048576
            $segment = [ArraySegment[byte]]::new($buffer)
            $result = $script:ws.ReceiveAsync($segment, $script:ct).GetAwaiter().GetResult()
            [void]$chunks.Append([Text.Encoding]::UTF8.GetString($buffer, 0, $result.Count))
        } while (-not $result.EndOfMessage)
        $parsed = $chunks.ToString() | ConvertFrom-Json
        $messages = @($parsed)
        foreach ($msg in $messages) {
            if ($msg.id -eq $script:cdpId) {
                return $msg
            }
        }
    }
}

[void](Send-Cdp "Runtime.enable" $null)

$fetchScript = @'
(async () => {
  const start = __START__;
  const end = __END__;

  const gql = async (query, variables) => {
    const res = await fetch('/graphql', {
      method: 'POST',
      headers: { 'content-type': 'application/json' },
      body: JSON.stringify({ query, variables })
    });
    const json = await res.json();
    if (json.errors) throw new Error(JSON.stringify(json.errors));
    return json.data;
  };

  const byId = new Map();
  const allProblemsRes = await fetch('/api/problems/all/');
  const allProblems = await allProblemsRes.json();
  for (const pair of allProblems.stat_status_pairs || []) {
    byId.set(Number(pair.stat.frontend_question_id), {
      frontendQuestionId: pair.stat.frontend_question_id,
      title: pair.stat.question__title,
      titleSlug: pair.stat.question__title_slug,
      paidOnly: pair.paid_only
    });
  }

  const questionQuery = `query questionData($titleSlug: String!) {
    question(titleSlug: $titleSlug) {
      questionId
      frontendQuestionId: questionFrontendId
      title
      titleSlug
      difficulty
      content
      similarQuestions
      topicTags { name slug }
      solution { title content paidOnly }
    }
  }`;

  const playgroundQuery = `query fetchPlayground($uuid: String!) {
    playground(uuid: $uuid) { selectedLangSlug name isShared }
    allPlaygroundCodes(uuid: $uuid) { code langSlug }
  }`;

  const contentToMarkdown = (html) => {
    const doc = new DOMParser().parseFromString(html || '', 'text/html');
    const clean = (s) => (s || '').replace(/\u00a0/g, ' ').replace(/[ \t]+\n/g, '\n').trim();
    const lines = [];
    for (const child of [...doc.body.children]) {
      const tag = child.tagName.toLowerCase();
      if (tag === 'p') {
        const text = clean(child.innerText);
        if (!text) continue;
        if (/^Example\s+\d+:$/i.test(text)) lines.push('### ' + text.replace(':', ''));
        else if (/^Constraints:$/i.test(text)) lines.push('## Constraints');
        else lines.push(text);
        lines.push('');
      } else if (tag === 'pre') {
        lines.push('```text');
        lines.push(clean(child.innerText));
        lines.push('```');
        lines.push('');
      } else if (tag === 'ul') {
        for (const li of [...child.querySelectorAll(':scope > li')]) lines.push('- ' + clean(li.innerText));
        lines.push('');
      }
    }
    return lines.join('\n').replace(/\n{3,}/g, '\n\n').trim();
  };

  const decodeHtml = (html) => {
    const doc = new DOMParser().parseFromString(html || '', 'text/html');
    return doc.documentElement.textContent || '';
  };

  const lastSubheading = (text) => {
    const matches = [...(text || '').matchAll(/^#{4,6}\s+(.+)$/gm)];
    if (!matches.length) return '';
    return matches[matches.length - 1][1].trim();
  };

  const extractInlineCodes = (section) => {
    const codes = [];
    for (const match of section.matchAll(/```([^\n`]*)\n([\s\S]*?)```/g)) {
      const langHint = (match[1] || '').trim().split(/\s+/)[0].replace(/\[.*\]$/, '');
      const code = (match[2] || '').replace(/\r\n/g, '\n').trimEnd();
      if (!code.trim()) continue;
      codes.push({
        label: lastSubheading(section.slice(0, match.index)),
        langHint,
        code
      });
    }

    const doc = new DOMParser().parseFromString(`<main>${section}</main>`, 'text/html');
    for (const pre of [...doc.querySelectorAll('pre')]) {
      const codeEl = pre.querySelector('code');
      const className = codeEl ? codeEl.className : pre.className;
      const langClass = [...String(className || '').matchAll(/(?:language|lang)-([A-Za-z0-9_#+.-]+)/g)]
        .map(m => m[1])
        .find(Boolean) || '';
      const code = (codeEl ? codeEl.textContent : pre.textContent || '').replace(/\r\n/g, '\n').trimEnd();
      if (!code.trim()) continue;
      if (codes.some(existing => existing.code.trim() === code.trim())) continue;

      let label = '';
      let node = pre.previousElementSibling;
      while (node) {
        if (/^h[4-6]$/i.test(node.tagName)) {
          label = node.textContent.trim();
          break;
        }
        node = node.previousElementSibling;
      }

      codes.push({
        label,
        langHint: langClass,
        code: decodeHtml(code)
      });
    }

    return codes;
  };

  const out = [];
  for (let id = start; id <= end; id++) {
    const listed = byId.get(id);
    if (!listed) {
      out.push({ id, skipped: true, reason: 'Problem not found in problem list.' });
      continue;
    }

    const q = (await gql(questionQuery, { titleSlug: listed.titleSlug })).question;
    const solution = q.solution;
    if (!solution || !solution.content) {
      out.push({ id, slug: q.titleSlug, title: q.title, skipped: true, reason: 'No official editorial content available.' });
      continue;
    }

    const content = solution.content;
    const approachMatches = [...content.matchAll(/^#{2,3}\s+(Approach[^\n]+)/gm)];
    const solutionMatch = content.match(/^#{2,3}\s+(Solution[^\n]*)/m);
    const sections = approachMatches.map((match, index) => {
      const nextMatch = approachMatches[index + 1];
      const sectionStart = match.index + match[0].length;
      const sectionEnd = nextMatch ? nextMatch.index : content.length;
      return { heading: match[1].trim(), content: content.slice(sectionStart, sectionEnd), index: index + 1 };
    });

    if (!sections.length) {
      const sectionStart = solutionMatch ? solutionMatch.index + solutionMatch[0].length : 0;
      sections.push({
        heading: solutionMatch ? solutionMatch[1].trim() : 'Official Solution',
        content: content.slice(sectionStart),
        index: 1
      });
    }

    const approaches = [];
    const codesByUuid = {};

    for (const section of sections) {
      const heading = section.heading;
      const approachContent = section.content;
      const iframeUrls = [...approachContent.matchAll(/<iframe[^>]+src="([^"]+)"/g)].map(m => m[1]);
      const playgroundUrl = iframeUrls.find(u => u.includes('/playground/'));
      let uuid = '';
      let inlineCodes = [];

      if (playgroundUrl) {
        uuid = playgroundUrl.split('/playground/')[1].split('/')[0];
        const playground = await gql(playgroundQuery, { uuid });
        codesByUuid[uuid] = playground.allPlaygroundCodes || [];
      } else {
        inlineCodes = extractInlineCodes(approachContent);
      }

      if (!uuid && !inlineCodes.length) continue;
      approaches.push({ heading, uuid, inlineCodes, index: section.index });
    }

    if (!approaches.length) {
      out.push({ id, slug: q.titleSlug, title: q.title, skipped: true, reason: 'Official editorial has no supported code snippets.' });
      continue;
    }

    out.push({
      id,
      slug: q.titleSlug,
      title: q.title,
      difficulty: q.difficulty,
      tags: q.topicTags || [],
      problemMarkdown: contentToMarkdown(q.content),
      similarQuestions: q.similarQuestions ? JSON.parse(q.similarQuestions) : [],
      solutionPaidOnly: solution.paidOnly,
      approaches,
      codesByUuid
    });
  }

  return JSON.stringify(out);
})()
'@
$fetchScript = $fetchScript.Replace("__START__", [string]$Start).Replace("__END__", [string]$End)

$response = Send-Cdp "Runtime.evaluate" @{ expression = $fetchScript; awaitPromise = $true; returnByValue = $true }
$ws.Dispose()

if ($response.result.exceptionDetails) {
    $details = $response.result.exceptionDetails | ConvertTo-Json -Depth 20
    throw "Chrome generator JavaScript failed: $details"
}

if (-not $response.result.result.value) {
    if ($response.exceptionDetails) {
        $details = $response.exceptionDetails | ConvertTo-Json -Depth 20
        throw "Chrome generator JavaScript failed: $details"
    }
    $rawResponse = $response | ConvertTo-Json -Depth 20
    Write-Output $rawResponse
    throw "Chrome did not return a generator payload."
}

$rawValue = $response.result.result.value
if ($null -ne $rawValue -and $rawValue -isnot [string]) {
    $rawValue = $rawValue | ConvertTo-Json -Depth 100 -Compress
}

if ($env:DEBUG_LEETCODE_GENERATOR) {
    Write-Output ("RAW_CDP_RESPONSE=" + ($response | ConvertTo-Json -Depth 20 -Compress))
    Write-Output ("RAW_TYPE=" + $(if ($null -eq $rawValue) { "<null>" } else { $rawValue.GetType().FullName }))
    Write-Output ("RAW_LENGTH=" + $(if ($null -eq $rawValue) { "<null>" } else { $rawValue.ToString().Length }))
    Write-Output ("RAW_GENERATOR_PAYLOAD=" + $rawValue)
}

$items = $rawValue | ConvertFrom-Json
$done = @()
$skipped = @()

foreach ($item in $items) {
    if ($item.skipped) {
        $skipped += [pscustomobject]@{ id = $item.id; title = $item.title; slug = $item.slug; reason = $item.reason }
        continue
    }

    $problemUrl = "https://leetcode.com/problems/$($item.slug)/"
    $folder = Convert-ToFolderName $item.id $item.title
    $problemDir = Join-Path $editorialRootPath $folder
    if (-not (Test-Path $problemDir)) {
        New-Item -ItemType Directory -Path $problemDir | Out-Null
    }
    $resolvedProblemDir = (Resolve-Path $problemDir).Path
    if (-not $resolvedProblemDir.StartsWith($editorialRootPath, [System.StringComparison]::OrdinalIgnoreCase)) {
        throw "Refusing to edit outside editorial root: $resolvedProblemDir"
    }

    $writtenLanguages = @{}
    foreach ($approach in $item.approaches) {
        $fileBase = Convert-ToFileBase $approach.index $approach.heading
        foreach ($entry in (Get-ApproachCodeEntries $item $approach)) {
            $langDir = Join-Path $problemDir $entry.Folder
            if (-not (Test-Path $langDir)) {
                New-Item -ItemType Directory -Path $langDir | Out-Null
            }
            $resolvedLangDir = (Resolve-Path $langDir).Path
            if (-not $resolvedLangDir.StartsWith($resolvedProblemDir, [System.StringComparison]::OrdinalIgnoreCase)) {
                throw "Refusing to edit outside problem root: $resolvedLangDir"
            }
            $filePath = Join-Path $langDir ($fileBase + "." + $entry.Ext)
            Write-Utf8NoBom $filePath ($entry.Code + "`n")
            $writtenLanguages[$entry.Key] = $true
        }
    }

    $tagText = (($item.tags | ForEach-Object { "``$($_.name)``" }) -join " ")
    $sb = [System.Text.StringBuilder]::new()
    [void]$sb.AppendLine("# $($item.id). $($item.title)")
    [void]$sb.AppendLine()
    [void]$sb.AppendLine((Convert-TopBadge $item.difficulty $problemUrl) + "  ")
    if ($tagText) { [void]$sb.AppendLine($tagText) }
    [void]$sb.AppendLine()
    [void]$sb.AppendLine("**Problem Link:** [LeetCode $($item.id) - $($item.title)]($problemUrl)")
    [void]$sb.AppendLine()
    [void]$sb.AppendLine("## Problem")
    [void]$sb.AppendLine()
    [void]$sb.AppendLine($item.problemMarkdown.Trim())
    [void]$sb.AppendLine()
    [void]$sb.AppendLine("## Similar Problems")
    [void]$sb.AppendLine()
    [void]$sb.AppendLine("| Problem | Difficulty |")
    [void]$sb.AppendLine("|---|:---:|")
    if ($item.similarQuestions.Count -eq 0) {
        [void]$sb.AppendLine("| None listed |  |")
    } else {
        foreach ($similar in $item.similarQuestions) {
            $badge = Convert-DifficultyBadge $similar.difficulty
            [void]$sb.AppendLine("| [$($similar.title)](https://leetcode.com/problems/$($similar.titleSlug)/) | $badge |")
        }
    }
    [void]$sb.AppendLine()
    [void]$sb.AppendLine("<br>")
    [void]$sb.AppendLine("<br>")
    [void]$sb.AppendLine()
    [void]$sb.AppendLine("---")
    [void]$sb.AppendLine()
    [void]$sb.AppendLine("<br>")
    [void]$sb.AppendLine("<br>")
    [void]$sb.AppendLine()
    [void]$sb.AppendLine("# Editorial - $($item.id). $($item.title)")
    [void]$sb.AppendLine()
    [void]$sb.AppendLine("## Overview")
    [void]$sb.AppendLine()
    [void]$sb.AppendLine("This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.")
    [void]$sb.AppendLine()
    [void]$sb.AppendLine("| Approach | Languages |")
    [void]$sb.AppendLine("|---|---|")
    foreach ($approach in $item.approaches) {
        $languageLabels = @(Get-ApproachCodeEntries $item $approach | ForEach-Object { $_.Label } | Select-Object -Unique)
        $headingShort = $approach.heading -replace "^Approach\s+\d+:\s*", ""
        [void]$sb.AppendLine("| $headingShort | $($languageLabels -join ', ') |")
    }
    [void]$sb.AppendLine()

    for ($i = 0; $i -lt $item.approaches.Count; $i++) {
        $approach = $item.approaches[$i]
        [void]$sb.AppendLine("## $($approach.heading)")
        [void]$sb.AppendLine()
        [void]$sb.AppendLine("### Implementation")
        [void]$sb.AppendLine()
        foreach ($entry in (Get-ApproachCodeEntries $item $approach)) {
            [void]$sb.AppendLine("<details>")
            [void]$sb.AppendLine("<summary><strong>$($entry.Label)</strong></summary>")
            [void]$sb.AppendLine()
            [void]$sb.AppendLine('```' + $entry.Fence)
            [void]$sb.AppendLine($entry.Code)
            [void]$sb.AppendLine('```')
            [void]$sb.AppendLine()
            [void]$sb.AppendLine("</details>")
            [void]$sb.AppendLine()
        }
        if ($i -lt $item.approaches.Count - 1) {
            [void]$sb.AppendLine("<br>")
            [void]$sb.AppendLine()
        }
    }

    Write-Utf8NoBom (Join-Path $problemDir "README.md") ($sb.ToString().TrimEnd() + "`n")
    $done += [pscustomobject]@{ id = $item.id; title = $item.title; folder = $folder; approaches = $item.approaches.Count; languages = $writtenLanguages.Count }
}

[pscustomobject]@{
    start = $Start
    end = $End
    done = $done
    skipped = $skipped
} | ConvertTo-Json -Depth 8
