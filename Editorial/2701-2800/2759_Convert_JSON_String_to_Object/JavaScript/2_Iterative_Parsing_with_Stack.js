var jsonParse = function(str) {
   const length = str.length;
   const stack = [];  // Stack to maintain the hierarchy of nested structures.
   let currentStruct = null;  // Current structure being processed (either an array or an object).
   let root = null;  // Root structure of the parsed JSON.
   let currentKey = null;  // Key for the current object value being processed.

   for(let i = 0; i < length; i++){
      if(str[i] === ",") continue;  // Skip commas.

      switch(str[i]) {
         case '[':
         case '{':
            const newStruct = str[i] === '[' ? [] : {};

            // If this is the first structure, set it as root.
            if (root === null) root = newStruct;

            if (currentStruct !== null) {
               if (Array.isArray(currentStruct)) {
                  currentStruct.push(newStruct);
               } else {
                  currentStruct[currentKey] = newStruct;
                  currentKey = null;
               }
            }

            stack.push(currentStruct);
            currentStruct = newStruct;  // Update the current structure.
            break;

         case ']':
         case '}':
            // End of current structure. Pop from the stack to go up one level.
            currentStruct = stack.pop();
            break;

         default:
            // Parse a value (either string, number, boolean, or null).
            let value = null;

            if(str[i] === '"') {  // String value.
               let j = i + 1;
               while(i + 1 < length && str[i + 1] !== '"') i++;
               value = str.substring(j, i + 1);
               i++;
            } else if(str[i] === '-' || ('0' <= str[i] && str[i] <= '9')) {  // Number value.
               let j = i;
               while(i + 1 < length && (str[i + 1] === '-' ||
                       ('0' <= str[i + 1] && str[i + 1] <= '9') ||
                       str[i + 1] === '.')) {
                  i++;
               }
               value = Number(str.substring(j, i + 1));
            } else {  // Boolean or null value.
               if(i + 4 <= length && str.substring(i, i + 4) === "true") {
                  value = true;
                  i += 3;
               } else if(i + 5 <= length && str.substring(i, i + 5) === "false") {
                  value = false;
                  i += 4;
               } else {
                  value = null;
                  i += 3;
               }
            }

            if (root === null) root = value;  // If this is the first value, set it as root.

            if(str[i + 1] === ":") {  // Object key.
               currentKey = value;
               i++;
            } else if(Array.isArray(currentStruct)) {  // Array value.
               currentStruct.push(value);
            } else if(currentKey !== null) {  // Object value.
               currentStruct[currentKey] = value;
               currentKey = null;
            } else {
               currentStruct = value;
            }
            break;
      }
   }

   return root;
};
