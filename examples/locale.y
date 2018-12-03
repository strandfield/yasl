import core;

Locale l = Locale::system();
String day = l.dayName(1, Locale::LongFormat);
print("First day of the week is: " + day);

String month = l.monthName(2);
print("Second month of the year is: " + month);

String country = l.nativeCountryName();
print("You are probably living in " + country);

String lang = l.nativeLanguageName();
print("Your language: " + lang);
