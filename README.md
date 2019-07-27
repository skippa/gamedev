# gamedev
Learning to code gamedev with C/C++ and Simple2D

My 11 year old took an interest in C/C++ mainly because he wants to do Arduino projects.  This led him to simple display libraries like Simple2D.  As he's doing more coding I thought I'd brush up on my skills.

Enjoy!


## Bouncing Balls

First, I made a ball bounce around at 45 deg angles.  I hacked my way through then cleaned up the code using some `struct` and array so I could do many balls bouncing around.


## Gravity and Vectors

Then I went down the rabbithole of math for game developers.  Sure, I could use Box2D or Chipmunk to implement physics, but I'd much rather learn the first principles.  It'll make it easier to teach my kids about it later.  Found this [awesome playlist](https://www.youtube.com/playlist?list=PLW3Zl3wyJwWOpdhYedlD-yCB7WQoHf-My), its based on C++ but I've been able to translate it to C (main problem is operator overloading not available in C).


## Other Physics Co-efficients

Once I've mastered gravity and vectors, I plan to try to simulate other forces like co-efficient of restitution, friction or maybe even magnus effect of a spinning ball.
