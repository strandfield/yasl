import core;
import gui;

Widget & w = newWidget("Hello there !");
w.show();
// Not consistent with connect()
// We must do something about this...
Timer::singleShot(2000, w, "1close()"); 
