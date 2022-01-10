////from Shakil Ahmed's Blog
int input[ 100005] , n ;
void LIS_with_set()
{
    set < int > lis ;
    set < int > :: iterator  it ; 
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",&input[i]);
        lis.insert( input[i]);
        it = lis.find( input[i]);
        it++;
        /*if its not the end of lis then removing it position
        value for better small value on that position */
        if( it != lis.end()) lis.erase(it); 
    }
    cout << lis.size() << endl ;
}
//using multiset then apply upper_bound we can find LIS for duplicate value .
void LIS_with_multiset()
{
    multiset < int > lis ;
    multiset < int > :: iterator  it ;
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",&input[i]);
        lis.insert( input[i]);
        it = lis.upper_bound( input[i]);
        if( it != lis.end()) lis.erase(it);
    }
    cout << lis.size() << endl ;
}