import core;

UrlQuery query{"type=pie&color=green"};
Assert(query.queryItemValue("color", Url::PrettyDecoded) == "green");
