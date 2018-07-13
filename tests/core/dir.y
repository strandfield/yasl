import core;

Dir d = Dir::current();

Assert(d.exists());
AssertFalse(d.isEmpty(Dir::AllEntries));