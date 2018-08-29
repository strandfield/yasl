import widgets;

Widget & w = newWidget("Hello there!");
Ref<Widget> parent_ref = w.parentWidget();
bool valid = parent_ref.isValid();