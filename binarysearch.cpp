long long l = 0, r = n;
//l is lowest possible, r is lowest not possible
while (r - l > 1){
  long long m = (l+r)/2;
  if (func(m)){
    l = m;
  }
  else {
    r = m;
  }
 }
return l;
