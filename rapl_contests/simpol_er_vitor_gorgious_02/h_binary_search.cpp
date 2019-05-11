
#include<bits/stdc++.h>
using namespace std ;
#define LL long long
char s[100005] ;
LL n , x ;
LL cnt_s[100005] ;
LL cnt_m[100005] ;
LL cnt_sm[100005] ;
LL cnt_ms[100005] ;
LL cnt_sms[100005] ;


void Precal()
{
    LL i ;

    // Making the string 1 based
    for( i = n ; i >= 1 ; i -- ) s[i] = s[i-1] ;

    //Memset
    memset( cnt_s , 0 , sizeof cnt_s ) ;
    memset( cnt_m , 0 , sizeof cnt_m ) ;
    memset( cnt_sm , 0 , sizeof cnt_sm ) ;
    memset( cnt_ms , 0 , sizeof cnt_ms ) ;
    memset( cnt_sms , 0 , sizeof cnt_sms ) ;

    // Cumulative sum of number of s
    for( i = 1 ; i <= n ; i ++ )
    {
        if( s[i] == 's' ) cnt_s[i] = 1 ;
        cnt_s[i] += cnt_s[i-1] ;
    }

    // Cumulative sum of number of m
    for( i = 1 ; i <= n ; i ++ )
    {
        if( s[i] == 'm' ) cnt_m[i] = 1 ;
        cnt_m[i] += cnt_m[i-1] ;
    }

    // Cumulative sum of number of sm
    LL t_s = 0 , t_sm = 0 ;
    for( i = 1 ; i <= n ; i ++ )
    {
        if( s[i] == 's' )
        {
            t_s ++ ;
        }
        else if( s[i] == 'm' )
        {
            t_sm += t_s ;
        }
        cnt_sm[i] = t_sm ;
    }

    // Cumulative sum of number of ms
    LL t_m = 0 , t_ms = 0 ;
    for( i = 1 ; i <= n ; i ++ )
    {
        if( s[i] == 'm' )
        {
            t_m ++ ;
        }
        else if( s[i] == 's' )
        {
            t_ms += t_m ;
        }
        cnt_ms[i] = t_ms ;
    }

    // Cumulative sum of number of sms
    LL t_sms = 0 ;
    t_s = 0 , t_sm = 0 ;
    for( i = 1 ; i <= n ; i ++ )
    {
        if( s[i] == 'm' )
        {
            t_sm += t_s ;
        }
        else if( s[i] == 's' )
        {
            t_s ++ ;
            t_sms += t_sm ;
        }
        cnt_sms[i] = t_sms ;
    }
}

LL Cal_ms( LL L , LL R )
{
    return cnt_ms[R] - cnt_ms[L-1] - ( cnt_m[L-1] * ( cnt_s[R] - cnt_s[L-1] ) ) ;
}

LL Cal( LL L , LL R )
{
    LL tot = cnt_sms[R] - cnt_sms[L-1] ;
    tot -= ( cnt_sm[L-1] * ( cnt_s[R] - cnt_s[L-1] ) ) ;
    tot -= ( cnt_s[L-1] * Cal_ms( L , R ) ) ;
    return tot ;
}

LL Fun( LL start_pos )
{
    LL left = start_pos , right = n , mid , res = 0 ;

    while( left <= right )
    {
        mid = left + ( right - left ) / 2 ;
        LL d = Cal( start_pos , mid ) ;
        if( d == x )
        {
            res = mid ;
            left = mid + 1 ;
        }
        else if( d < x ) left = mid + 1 ;
        else right = mid - 1 ;
    }
    return res ;
}

pair<LL,LL> Solve( )
{
    LL i ;
    bool ok = 0 ;
    pair<LL,LL> Res ;
    for( i = 1 ; i <= n ; i ++ )
    {
        LL last_pos = Fun( i ) ;
        if( last_pos )
        {
            if( ok && ( last_pos - i + 1 ) > ( Res.second - Res.first + 1 ) )
            {
                Res.first = i , Res.second = last_pos ;
            }
            else if( !ok )
            {
                ok = 1 ;
                Res.first = i , Res.second = last_pos ;
            }
        }
    }
    if( !ok ) Res.first = 0 , Res.second = -1 ;
    return Res ;

}

int main()
{
    LL t , i , j , k , q , caseno ;
    scanf("%lld",&t) ;
    for( caseno = 1 ; caseno <= t ; caseno ++ )
    {
        pair<LL,LL> res ;
        scanf("%s",s) ;
        n = strlen( s ) ;

        scanf("%lld",&x) ;

        Precal() ;

        res = Solve() ;

        if( res.first )
        {
            printf("%lld %lld\n",res.first,res.second) ;
        }
        else
        {
            printf("%lld\n",res.second) ;
        }
    }
    return 0 ;
}

