function curry(fn: Function): Function {
   return function curried(...args: any[]): any {
      if (args.length >= fn.length) {
         return fn(...args);
      }

      return (...nextArgs: any[]): any => curried(...args, ...nextArgs);
   }
};
