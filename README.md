
**Page Replacement algorithms**

These are the algorithms that are used to manage virtual-memory.
Here in this repo I have done 3 of these:

  (i)_FIFO_
  
     This technique is "First in First Out" i.e when a page fault occurs it replaces the page that is the oldest
     frame in the main memory or replace the frame that has been in the memory for longest time.
  (ii)_LRU_
  
     This technique is "Least Recently Used" i.e when a page fault occurs it checks for the frame that is not occured 
     recently (it maintains a counter for every frame when there is a hit the counter resets to 0 and when a page fault
     occurs it checks the counters of every frame that is largest)
  (iii)_OPTIMAL_
  
     This technique is "Optimal" i.e when a page fault occurs it checks for the frame that will nnot occur most recently 
