#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Intrinsic.h>
#include <X11/extensions/XTest.h>
#include <X11/keysym.h>


int main()
{
        Display *dis;
        dis = XOpenDisplay(NULL);
        KeyCode modcode = 0; //init value
        int i;
        char hello[]="hello";
        for (i=0;i<5;i++)
        {
                modcode = XKeysymToKeycode(dis, XStringToKeysym("Up"));
                XTestFakeKeyEvent(dis, modcode, False, 0);
                XFlush(dis);
        //      sleep(1);
                XTestFakeKeyEvent(dis, modcode, True, 0);
                XFlush(dis);
                XTestFakeKeyEvent(dis, modcode, False, 0);
                XFlush(dis);
}



        return 0;
}
