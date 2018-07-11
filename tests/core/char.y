import core;

Assert(Char::isLetter('A'));
AssertFalse(Char::isLetter('8'));
Assert(Char::isLetterOrNumber('8'));
Assert(Char::digitValue('8') == 8);