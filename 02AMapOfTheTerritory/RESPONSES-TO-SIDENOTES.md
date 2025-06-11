Author: There are certainly dead ends, sad little cul-de-sacs of CS papers with zero citations and now-forgotten optimizations that only made sense when memory was measured in individual bytes.
Chrissie: There are certainly dead ends, one day, AI conversational models will give everyone the power to create software such that CS degrees become toilet paper and the only sweet stuff will be problem solving skills.

Author: “Lexical” comes from the Greek root “lex”, meaning “word”.
Chrissie: The Greeks are gone, they got K.O. by the Romans. Same way these AI conversational models will K.O. CS degrees.

Author: The language we’ll build in this book is dynamically typed, so it will do its type checking later, at runtime.
Chrissie: What do you mean, we? You mean the language I am going to write!

Author: There are a few well-established styles of IRs out there. Hit your search engine of choice and look for “control flow graph”, “static single-assignment”, “continuation-passing style”, and “three-address code”.
Chrissie: I found them on Geeks 4 Geeks.

Author: If you’ve ever wondered how GCC supports so many crazy languages and architectures, like Modula-3 on Motorola 68k, now you know. Language front ends target one of a handful of IRs, mainly GIMPLE and RTL. Target back ends like the one for 68k then take those IRs and produce native code.
Chrissie: I thought some lifeless dweeb spent his miserable life writing the compilers for all of them.

Author: If you can’t resist poking your foot into that hole, some keywords to get you started are “constant propagation”, “common subexpression elimination”, “loop invariant code motion”, “global value numbering”, “strength reduction”, “scalar replacement of aggregates”, “dead code elimination”, and “loop unrolling”.
Chrissie: Very easy for me to resist poking my foot into the hole, idk about my stick.

Author: For example, the AAD (“ASCII Adjust AX Before Division”) instruction lets you perform division, which sounds useful. Except that instruction takes, as operands, two binary-coded decimal digits packed into a single 16-bit register. When was the last time you needed BCD on a 16-bit machine?
Chrissie: I was in my father's ball sac when that came around.

Author: The basic principle here is that the farther down the pipeline you push the architecture-specific work, the more of the earlier phases you can share across architectures.
Chrissie: Reminds me of deep diving.

Author: There is a tension, though. Many optimizations, like register allocation and instruction selection, work best when they know the strengths and capabilities of a specific chip. Figuring out which parts of your compiler can be shared and which should be target-specific is an art.
Chrissie: An art for me is something beautiful worth staring at.

Author: The term “virtual machine” also refers to a different kind of abstraction. A system virtual machine emulates an entire hardware platform and operating system in software. This is how you can play Windows games on your Linux machine, and how cloud providers give customers the user experience of controlling their own “server” without needing to physically allocate separate computers for each user.
Chrissie: Yet Apple still makes more money from Hardware, y'all can't product real art.

Author: The kind of VMs we’ll talk about in this book are language virtual machines or process virtual machines if you want to be unambiguous.
Chrissie: Cool beans.

Author: Syntax-directed translation is a structured technique for building these all-at-once compilers. You associate an action with each piece of the grammar, usually one that generates output code. Then, whenever the parser matches that chunk of syntax, it executes the action, building up the target code one rule at a time.
Chrissie: Makes C function declaration more respectable.

Author: A notable exception is early versions of Ruby, which were tree walkers. At 1.9, the canonical implementation of Ruby switched from the original MRI (Matz’s Ruby Interpreter) to Koichi Sasada’s YARV (Yet Another Ruby VM). YARV is a bytecode virtual machine.
Chrissie: I remember implementing a very simple tree walker for a calc game I made for my high school senior project.

Author: The first transcompiler, XLT86, translated 8080 assembly into 8086 assembly. That might seem straightforward, but keep in mind the 8080 was an 8-bit chip and the 8086 a 16-bit chip that could use each register as a pair of 8-bit ones. XLT86 did data flow analysis to track register usage in the source program and then efficiently map it to the register set of the 8086.
Chrissie: I was in my father's ball sack at the time.

Author: It was written by Gary Kildall, a tragic hero of computer science if there ever was one. One of the first people to recognize the promise of microcomputers, he created PL/M and CP/M, the first high-level language and OS for them.
Chrissie: You need a better hero like God.

Author: He was a sea captain, business owner, licensed pilot, and motorcyclist. A TV host with the Kris Kristofferson-esque look sported by dashing bearded dudes in the ’80s. He took on Bill Gates and, like many, lost, before meeting his end in a biker bar under mysterious circumstances. He died too young, but sure as hell lived before he did.
Chrissie: Nevermind, he seemed pretty bad @ss. I bet Bill hired a hitman.

Author: JS used to be the only way to execute code in a browser. Thanks to WebAssembly, compilers now have a second, lower-level language they can target that runs on the web.
Chrissie: You learn something new every day.

Author: This is, of course, exactly where the HotSpot JVM gets its name.
Chrissie: There's nothing hot about sections of code.

Author: Peanuts (which are not even nuts) and cereals like wheat are actually fruit, but I got this drawing wrong. What can I say, I’m a software engineer, not a botanist. I should probably erase the little peanut guy, but he’s so cute that I can’t bear to.
Chrissie: There's nothing cute about the peanut guy.

Author: Now pine nuts, on the other hand, are plant-based foods that are neither fruits nor vegetables. At least as far as I can tell.
Chrissie: You need to eat steak.

Author: The Go tool is even more of a horticultural curiosity. If you run go build, it compiles your Go source code to machine code and stops. If you type go run, it does that, then immediately executes the generated executable.
Chrissie: Nothing special, just common sense.

Author: So go is a compiler (you can use it as a tool to compile code without running it), is an interpreter (you can invoke it to immediately run a program from source), and also has a compiler (when you use it as an interpreter, it is still compiling internally).
Chrissie: Nothing special, just Go and an executable. 

Author: Henceforth, I promise to tone down the whole mountain metaphor thing.
Chrissie: Finally.

