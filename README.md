**Key concepts**

Page: A fixed-size block of memory or data in the process's logical address space.

Page Frame: A fixed-size block of physical memory that can hold one page.

Page Fault: Occurs when a program tries to access a page that is not currently in physical memory.

**Page Replacement algorithms**

These are the algorithms that are used to manage virtual-memory.
Here in this repo I have done 3 of these:

  (i)**FIFO**
  
     This technique is "First in First Out" i.e when a page fault occurs it replaces the page that is the oldest
     frame in the main memory or replace the frame that has been in the memory for longest time.
  (ii)**LRU**
  
     This technique is "Least Recently Used" i.e when a page fault occurs it checks for the frame that is not occured 
     recently (it maintains a counter for every frame when there is a hit the counter resets to 0 and when a page fault
     occurs it checks the counters of every frame that is largest)
  (iii)**OPTIMAL**
  
     This technique is "Optimal" i.e when a page fault occurs it checks for the frame that will nnot occur most recently 
