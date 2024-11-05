/*
move does not throw exceptions because it simply steals resources - so use noexcept
leave the move from object in a good state to destroy e.g. setting it nullptr but must also leave it in a valid state
if a class has custom copy constructor, copy-assignment or destructor, a move constructor or move-assignment operator are not synthetized
*/
