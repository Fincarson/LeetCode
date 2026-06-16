let intervalIdCounter = 0;
const intervalMap = new Map(); // To store timer IDs

function customInterval(fn, delay, period){
  let count = 0;
  const customId = intervalIdCounter++; // Generate a unique ID

  function dfs() {
    const timerId = setTimeout(() => {
      fn();
      dfs();
    }, delay + period * count);
    count++;
    intervalMap.set(customId, timerId); // Store timer ID
  }

  dfs();

  return customId;
}

function customClearInterval(id) {
  // Retrieve the timer ID associated with the custom ID
  const timerId = intervalMap.get(id);
  clearTimeout(timerId);
  intervalMap.delete(id);
}
