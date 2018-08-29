import core;
import widgets;

Widget & w = newWidget();
Locale l = Locale::system();
String day = l.dayName(1, Locale::LongFormat);
w.setWindowTitle(day);
w.show();