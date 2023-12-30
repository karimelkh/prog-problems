template <class t>
bool is_neg(t x) {return x < 0;}

template <class t>
bool is_pos(t x) {return x >= 0;}

template <class t>
t abs_val(t x) {
  if(x < 0) x *= -1;
  return x;
}

template <class t>
t pwr(t x, int exp) {
  if(exp == 0) return 1;
  t r = 1;
  for(int i=1; i<=exp; i++) r*=x;
  return r;
}

// is_odd
// is_even