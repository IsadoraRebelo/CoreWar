#something

.name "zork"
.comment "just a basic living prog"
		
sti	r1,%2,%0
	and	r1,%0,r1
live	%1
	zjmp	%2
