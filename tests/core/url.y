import core;

Url url{"http://www.qt.io/index.html", Url::StrictMode};
Assert(url.scheme() == "http");
Assert(url.host(Url::FullyDecoded) == "www.qt.io");