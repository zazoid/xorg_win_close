Just an example of xorg protocol interacion. I had a problem that my favourite and almost abadoned EvilWM justified it's name by killing whole app when I tried to close just a little modal window - sperctum analyzer in Ardour. Closing it was literally totally impossible by any means. Hotkey simply wasn't defined for that particular window - someone simply forgot... that was the last straw, and that's how this story begun. Begun to resolving. I had different issues with complex gui apps for years, but especially this one was bloodies. Several times I lost a lot of work because of this bug(that also happened in Reaper before), another example - xfce4-terminal, closing one window with usual hotkey killed all of them in all workspaces. Don't ask why xfce4-terminal in evilwm, I dont' know, why not?

It would seem that time has come to change the window manager, but what could be more depressing than the stupid memorization of new bindings in that everyone-loved i3, which I consider bloatware, by the way... What useful experience will I take from this? Another thing is to fix a bug in a tiny app that noone needs! Try to find WM that is less known than evilwm! Just try! It may exist, but will you find it..? Even though I haven't programmed in C for many years, it turned out to be not so difficult task. With the help of GDB, I found the place in code where the problem occurred, but before changing this code, I decided to implement an example test application that calls proper xorg protocol method. By the way, I didn’t take the main evilvm repository as a basis, because I was hoping that someone had already solved this problem, and this is almost true for the [mati75/evilwm](https://github.com/mati75/evilwm) This repo was taken as basis instead. It differs significantly and there is handling of different versions of the protocol, and many other internal differences, but ... it also doesn’t work! It fails exactly the same way and in the same place. I'm not sure and I don't have free time to investigate it right now, but it looks like xorg protocol changed twice(!) even though we haven't even switched to wayland yet!(I hope I'm wrong!) But why only one of the simplest functions broke? The problem was very local and even with my modest С skills I managed to solve it in one day and one night. What about the example app - that's it! It might be useful for someone

Almost forgot: [my evilwm fork](https://github.com/zazoid/evilwm)
