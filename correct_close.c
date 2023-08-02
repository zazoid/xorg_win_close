
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xresource.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include <X11/Xatom.h>




int
        main
            (int argc , char* argv[ ] ){


    int screen_num, width, height;
    unsigned long background, border;
    Window win;
    XEvent ev;

    Atom protocol_atom;

    Display* display;
    char* connection_string = NULL;
    display = XOpenDisplay (connection_string  );
    if (display == NULL ){
        fprintf (stderr, "Error: XOpenDisplay (%s )\n", connection_string == NULL ? "NULL" :  connection_string );
        exit (EXIT_FAILURE );}


    protocol_atom = XInternAtom(display, "WM_DELETE_WINDOW", False);

    screen_num = DefaultScreen(display);
    background = BlackPixel(display, screen_num);
    border = WhitePixel(display, screen_num);

    width = 140;
    height = 140;



    win = XCreateSimpleWindow(display, RootWindow(display,screen_num),0,0,width, height, 2, border, background);



    /* tell the display server what kind of events we would like to see */
    XSelectInput(display, win, ButtonPressMask|StructureNotifyMask );
//     XSelectInput(display, win, ExposureMask | KeyPressMask );


    /* okay, put the window on the screen, please */
    XMapWindow(display, win);

    XSetWMProtocols(display, win, &protocol_atom, 1);

    while(1){
            XNextEvent(display, &ev);
            switch(ev.type){
            case ConfigureNotify:
                if (width != ev.xconfigure.width
                        || height != ev.xconfigure.height) {
                    width = ev.xconfigure.width;
                    height = ev.xconfigure.height;
                    printf("Size changed to: %d by %d", width, height); 
                }
                break;
            case ButtonPress:
                if (protocol_atom) {
                    printf("we have atom to do destroy");
                    XEvent ev = {
                        .xclient = {
                        .type = ClientMessage,
                        .window = win,
                        .message_type = XInternAtom(display, "WM_PROTOCOLS", True),
                        .format = 32,
                        .data.l[0] = protocol_atom
                            }
                        };
                    XSendEvent(display, win, False, NoEventMask, &ev);
                } else {
                    printf("defaulting to XKillClient");
                    XKillClient(display, win);
                }
                    XCloseDisplay(display);
            return 0;
            }
        }

    exit (EXIT_SUCCESS );}



