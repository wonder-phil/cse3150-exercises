template<typename Container, typename InputIterator>
void insert_into(Container & b, InputIterator from, InputIterator to) {
  while (from != to) {
    b.push_back(*from);
    ++from;
  }
}