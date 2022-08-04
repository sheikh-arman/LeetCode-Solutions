class Solution {
public:
int mirrorReflection(int p, int q) {

    return (  (p/__gcd(q,p))%2==0?2:(q/__gcd(q,p))%2 );
}
};