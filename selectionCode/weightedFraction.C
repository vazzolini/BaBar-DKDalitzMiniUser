void weightedFraction(int n1, int n1tot, int n2, int n2tot, double w1=1., double w2=1.)
{
  double num = w1*double(n1)+w2*double(n2);
  double den = w1*double(n1tot)+w2*double(n2tot);
  double mu = num/den;
  double sigma = sqrt(num*(1.-mu))/den;
  cout << mu << " +/-" << sigma << endl;
}
