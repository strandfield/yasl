import core;

RegularExpression reg{"Q(.*)", RegularExpression::NoPatternOption};
RegularExpressionMatch match = reg.match("QRegularExpression", 0, RegularExpression::NormalMatch, RegularExpression::NoMatchOption);
Assert(match.hasMatch());
Assert(match.captured(1) == "RegularExpression");