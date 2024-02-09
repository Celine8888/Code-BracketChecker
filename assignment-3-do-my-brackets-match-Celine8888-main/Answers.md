# Assignment 3: Answers

**Complete this document, commit your changes to Github and submit the repository URL to Canvas.** Keep your answers short and precise.

Your Name:

Used free extension: [ ] 24 hrs or [ ] 48 hrs

[ ] Early submission (48 hrs)

[ ] Bonus work. Describe: ...

Place [x] for what applies.


## Answers
1. How long did the program take with each version (You will need more than the test data)?  Describe what differences in run time you expect for your implementation. What you see in your experiments?

   > List(bad: 1636 milliseconds, difficult: 1589 milliseconds, good: 1346 milliseconds)
   Array(bad: 1171 milliseconds, difficult: 1827 milliseconds, good: 1385 milliseconds)
   
   List(DSString.h: 1173 milliseconds, DSString.cpp: 1738 milliseconds)
   Array(DSString.h: 1669 milliseconds, DSString.cpp: 1553 milliseconds)

   List(SentimentClassifier.cpp: 1423 milliseconds, SentimentClassifier.h: 1360 milliseconds, test_DSString.cpp: 1202 milliseconds)
   Array(SentimentClassifier.cpp: 1913 milliseconds, SentimentClassifier.h: 1005 milliseconds, test_DSString.cpp: 1803 milliseconds)

   The list is faster than the array in 5 out of 8 cases. I expected the list to be faster everytime, but it surprised me that the fact is 'most of the time' 

2. Discuss the difference in memory usage based on your implementation. You will need to think about how the versions store data.

   > The list finds memory freely on the heap, and attach it to my List using pointers. The array is continuous memory and needs to copy everything to another location if overflow. So the array has a higher requirement for memory allocation.

3. Which version would you use in practice. Why?

   > I would use the list, because of memory efficiency and speed.

4. Make sure that your stack implementation does not have memory leaks.

   ```
   List:
   Checking all files took 53349 milliseconds
==29696== 
==29696== HEAP SUMMARY:
==29696==     in use at exit: 0 bytes in 0 blocks
==29696==   total heap usage: 232 allocs, 232 frees, 85,293 bytes allocated
==29696== 
==29696== All heap blocks were freed -- no leaks are possible
==29696== 
==29696== For lists of detected and suppressed errors, rerun with: -s
==29696== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0) 

   Array:
   Checking all files took 53764 milliseconds
==29852== 
==29852== HEAP SUMMARY:
==29852==     in use at exit: 0 bytes in 0 blocks
==29852==   total heap usage: 14 allocs, 14 frees, 81,752 bytes allocated
==29852== 
==29852== All heap blocks were freed -- no leaks are possible
==29852== 
==29852== For lists of detected and suppressed errors, rerun with: -s
==29852== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


   ```

5. Did you attempt any bonuses? If so, please give a brief description of what you did.

   > No.
