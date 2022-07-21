int prime[100000001/64+4];
int check(ll n){
    return prime[n>>6]&(1<<((n>>1)&31));
}
void seter(ll n){
    prime[n>>6]|=(1<<((n>>1)&31));
}
void bitwise_seive(ll p){
    for(ll i=3; i*i<=p; i+=2){
        if(check(i)==0){
            for(int ll j=i*i; j<=p; j+=(2*i)){
                seter(j);
            }
        }
    }
    vprime.pb(2);
    for(ll i=3; i<=p; i+=2){
        if(check(i)==0){
            vprime.pb(i);
        }
    }
    return;
}