#include <fstream>
#include <assert.h>

#include "matrix.h"

using namespace common;
using namespace std;

void ex6_2()
{
	ofstream log( "logmatrix.txt" );
	if ( ! log )
		{ cerr << "can't open log file!\n"; return; }

	common::Matrix<float> identity( 4, 4 );
    log << "identity: " << identity << endl;

	float ar[16]={
		1., 0., 0., 0., 0., 1., 0., 0.,
		0., 0., 1., 0., 0., 0., 0., 1. };

	for ( int i = 0, k = 0; i < 4; ++i )
		for ( int j = 0; j < 4; ++j )
		    identity( i, j ) = ar[ k++ ];

	log << "identity after set: " << identity << endl;

	common::Matrix<float> m( identity );
	log << "m: memberwise initialized: " << m << endl; 
	
	common::Matrix<float> m2( 8, 12 );
	log << "m2: 8x12: " <<  m2  << endl;

	m2 = m;
	log << "m2 after memberwise assigned to m: " << m2 << endl;

	float ar2[16]={
		1.3f, 0.4f, 2.6f, 8.2f, 6.2f, 1.7f, 1.3f, 8.3f,
		4.2f, 7.4f, 2.7f, 1.9f, 6.3f, 8.1f, 5.6f, 6.6f };

	common::Matrix<float> m3( 4, 4 );

	for ( int ix = 0, kx = 0; ix < 4; ++ix )
		for ( int j = 0; j < 4; ++j )
		    m3( ix, j ) = ar2[ kx++ ];

	log << "m3: assigned random values: " << m3 << endl;

	common::Matrix<float> m4 = m3 * identity;
	log << m4 << endl;

	common::Matrix<float> m5 = m3 + m4;
	log << m5 << endl;

	m3 += m4;
	log << m3 << endl;
}

#include <vector>
#include <algorithm>
#include <iostream>

void test_rotate()
{
	char ch[] = "boohiss!!";
	rotate( ch, ch+3, ch+7 );
	cout << ch << endl;
}

int main()
{ 
	ex6_2();
	test_rotate();
	return 0; // unnecessary but quiets vc++
}