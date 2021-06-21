//This one use SMT encoding of the Sbox, it runs slower than the other one (not sure which is faster June 29)
//We also encode the partial DDT table
//The code is actully easlier to write with this method than the Hrepresentation one
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>

using namespace std;

int main(int argc, char *argv[]){
  const int T = atoi(argv[1]);
  const int bound = atoi(argv[2]);
  //const int AS = atoi(argv[3]);
  cout << "(set-logic QF_ABV)" << endl;
  cout << "(set-info :smt-lib-version 2.5)" <<endl;
  cout << "(set-option :produce-models true)" <<endl;
  for(int i=0; i<T; i++){      //declare variables
  for(int j=0; j<=15; j++){
		cout << "(declare-fun a"<<j<<"_"<<i<<" () (_ BitVec 4)) ";
		cout << "(declare-fun b"<<j<<"_"<<i<<" () (_ BitVec 4)) ";
	 cout << "(declare-fun pon"<<j<<"_"<<i<<" () (_ BitVec 1)) ";  //2^-2
	 cout << "(declare-fun ptw"<<j<<"_"<<i<<" () (_ BitVec 1)) ";  //2^-3
	 cout << "(declare-fun pth"<<j<<"_"<<i<<" () (_ BitVec 1)) ";  //2^-1.4
  }}
  for(int j=0; j<=15; j++){
    cout << "(declare-fun a"<<j<<"_"<<T<<" () (_ BitVec 4)) " ;
  }
  for(int i=0; i<T; i++){    //key from key schdule
  cout <<"(declare-fun k0_"<<i<<" () (_ BitVec 16)) "<< endl;
  cout <<"(declare-fun k1_"<<i<<" () (_ BitVec 16)) "<< endl;
  }
  for(int i=0; i<=T; i++){    //round keys
  for(int j=0; j<=15; j++){
		cout << "(declare-fun key"<<j<<"_"<<i<<" () (_ BitVec 4)) ";
  }}
  cout <<"(declare-fun weight1 () (_ BitVec 16))"<<endl;
  cout <<"(declare-fun weight2 () (_ BitVec 16))"<<endl;
  cout <<"(declare-fun weight3 () (_ BitVec 16))"<<endl;
  cout << endl;
  cout <<"(define-fun w_A ((x (_ BitVec 4))) (_ BitVec 16)  (bvor (bvand (bvlshr (concat (_ bv0 12) x) #x0003) #x0001) (bvor (bvand (bvlshr (concat (_ bv0 12) x) #x0002) #x0001) (bvor (bvand (concat (_ bv0 12) x) #x0001) (bvand (bvlshr (concat (_ bv0 12) x) #x0001) #x0001))))) ;test if an sbox(4-bit) is active" << endl;
  cout <<"(define-fun shuffle ((x3 (_ BitVec 4)) (x2 (_ BitVec 4)) (x1 (_ BitVec 4)) (x0 (_ BitVec 4))) (_ BitVec 4) (concat ((_ extract 3 3)x3) (concat ((_ extract 2 2)x2) (concat ((_ extract 1 1)x1) ((_ extract 0 0)x0)))))"<< endl;
  //----------------sbox-----------------//   gift
  for(int i=0; i<T; i++){  //DDT entries with 4. p-one
  for(int j=0; j<=15; j++){
    cout <<"(assert (= pon"<<j<<"_"<<i<<" (bvor ";
    cout <<"(bvand (= a"<<j<<"_"<<i<<" #x2) (bvor (= b"<<j<<"_"<<i<<" #x5) (= b"<<j<<"_"<<i<<" #x6))) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #x4) (= b"<<j<<"_"<<i<<" #x5)) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #x5) (= b"<<j<<"_"<<i<<" #xf)) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #x6) (= b"<<j<<"_"<<i<<" #x2)) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #x7) (= b"<<j<<"_"<<i<<" #xb)) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #x8) (bvor (= b"<<j<<"_"<<i<<" #x3) (bvor (= b"<<j<<"_"<<i<<" #x7) (bvor (= b"<<j<<"_"<<i<<" #xb) (= b"<<j<<"_"<<i<<" #xf))))) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #xa) (bvor (= b"<<j<<"_"<<i<<" #x1) (= b"<<j<<"_"<<i<<" #x6))) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #xc) (bvor (= b"<<j<<"_"<<i<<" #x2) (= b"<<j<<"_"<<i<<" #x4))) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #xd) (= b"<<j<<"_"<<i<<" #x4)) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #xe) (bvor (= b"<<j<<"_"<<i<<" #x1) (= b"<<j<<"_"<<i<<" #x4))) ";
    cout <<"(bvand (= a"<<j<<"_"<<i<<" #xf) (= b"<<j<<"_"<<i<<" #x4))) ";
    cout <<")))))))))))"<<endl;
  }}
  for(int i=0; i<T; i++){  //DDT entries with 2, p-two
  for(int j=0; j<=15; j++){
    cout <<"(assert (= ptw"<<j<<"_"<<i<<" (bvor ";
    cout <<"(bvand (= a"<<j<<"_"<<i<<" #x1) (bvor (= b"<<j<<"_"<<i<<" #x5) (bvor (= b"<<j<<"_"<<i<<" #x6) (bvor (= b"<<j<<"_"<<i<<" #x8) (bvor (= b"<<j<<"_"<<i<<" #x9) (bvor (= b"<<j<<"_"<<i<<" #xa) (bvor (= b"<<j<<"_"<<i<<" #xb) (bvor (= b"<<j<<"_"<<i<<" #xc) (= b"<<j<<"_"<<i<<" #xf))))))))) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #x2) (bvor (= b"<<j<<"_"<<i<<" #x9) (bvor (= b"<<j<<"_"<<i<<" #xa) (bvor (= b"<<j<<"_"<<i<<" #xd) (= b"<<j<<"_"<<i<<" #xe))))) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #x3) (bvor (= b"<<j<<"_"<<i<<" #x5) (bvor (= b"<<j<<"_"<<i<<" #x6) (bvor (= b"<<j<<"_"<<i<<" #x8) (bvor (= b"<<j<<"_"<<i<<" #xb) (bvor (= b"<<j<<"_"<<i<<" #xc) (bvor (= b"<<j<<"_"<<i<<" #xd) (bvor (= b"<<j<<"_"<<i<<" #xe) (= b"<<j<<"_"<<i<<" #xf))))))))) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #x4) (bvor (= b"<<j<<"_"<<i<<" #x3) (bvor (= b"<<j<<"_"<<i<<" #x9) (= b"<<j<<"_"<<i<<" #xd)))) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #x5) (bvor (= b"<<j<<"_"<<i<<" #x2) (bvor (= b"<<j<<"_"<<i<<" #x5) (bvor (= b"<<j<<"_"<<i<<" #x8) (bvor (= b"<<j<<"_"<<i<<" #xc) (bvor (= b"<<j<<"_"<<i<<" #xd) (= b"<<j<<"_"<<i<<" #xe))))))) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #x6) (bvor (= b"<<j<<"_"<<i<<" #x7) (bvor (= b"<<j<<"_"<<i<<" #xa) (= b"<<j<<"_"<<i<<" #xe)))) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #x7) (bvor (= b"<<j<<"_"<<i<<" #x2) (bvor (= b"<<j<<"_"<<i<<" #x5) (bvor (= b"<<j<<"_"<<i<<" #x8) (bvor (= b"<<j<<"_"<<i<<" #x9) (bvor (= b"<<j<<"_"<<i<<" #xa) (= b"<<j<<"_"<<i<<" #xc))))))) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #x9) (bvor (= b"<<j<<"_"<<i<<" #x1) (bvor (= b"<<j<<"_"<<i<<" #x3) (bvor (= b"<<j<<"_"<<i<<" #x6) (bvor (= b"<<j<<"_"<<i<<" #x7) (bvor (= b"<<j<<"_"<<i<<" #x8) (bvor (= b"<<j<<"_"<<i<<" #xa) (bvor (= b"<<j<<"_"<<i<<" #xc) (= b"<<j<<"_"<<i<<" #xd))))))))) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #xa) (bvor (= b"<<j<<"_"<<i<<" #x9) (bvor (= b"<<j<<"_"<<i<<" #xa) (bvor (= b"<<j<<"_"<<i<<" #xd) (= b"<<j<<"_"<<i<<" #xe))))) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #xb) (bvor (= b"<<j<<"_"<<i<<" #x1) (bvor (= b"<<j<<"_"<<i<<" #x3) (bvor (= b"<<j<<"_"<<i<<" #x6) (bvor (= b"<<j<<"_"<<i<<" #x7) (bvor (= b"<<j<<"_"<<i<<" #x8) (bvor (= b"<<j<<"_"<<i<<" #x9) (bvor (= b"<<j<<"_"<<i<<" #xc) (= b"<<j<<"_"<<i<<" #xe))))))))) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #xc) (bvor (= b"<<j<<"_"<<i<<" #x8) (bvor (= b"<<j<<"_"<<i<<" #xa) (bvor (= b"<<j<<"_"<<i<<" #xc) (= b"<<j<<"_"<<i<<" #xe))))) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #xd) (bvor (= b"<<j<<"_"<<i<<" #x1) (bvor (= b"<<j<<"_"<<i<<" #x2) (bvor (= b"<<j<<"_"<<i<<" #xa) (bvor (= b"<<j<<"_"<<i<<" #xb) (bvor (= b"<<j<<"_"<<i<<" #xd) (= b"<<j<<"_"<<i<<" #xf))))))) ";
    cout <<"(bvor (bvand (= a"<<j<<"_"<<i<<" #xe) (bvor (= b"<<j<<"_"<<i<<" #x8) (bvor (= b"<<j<<"_"<<i<<" #x9) (bvor (= b"<<j<<"_"<<i<<" #xc) (= b"<<j<<"_"<<i<<" #xd))))) ";
    cout <<"(bvand (= a"<<j<<"_"<<i<<" #xf) (bvor (= b"<<j<<"_"<<i<<" #x1) (bvor (= b"<<j<<"_"<<i<<" #x2) (bvor (= b"<<j<<"_"<<i<<" #x9) (bvor (= b"<<j<<"_"<<i<<" #xb) (bvor (= b"<<j<<"_"<<i<<" #xe) (= b"<<j<<"_"<<i<<" #xf))))))) ";
    cout <<")))))))))))))))"<<endl;
  }}
  for(int i=0; i<T; i++){  //DDT entries with 6, p-three
  for(int j=0; j<=15; j++){
    cout <<"(assert (= pth"<<j<<"_"<<i<<" (bvor ";
    cout <<"(bvand (= a"<<j<<"_"<<i<<" #x4) (= b"<<j<<"_"<<i<<" #x7)) ";
    cout <<"(bvand (= a"<<j<<"_"<<i<<" #x6) (= b"<<j<<"_"<<i<<" #x3)) ";
    cout <<")))"<<endl;
  }}

  for(int i=0; i<T; i++){
  for(int j=0; j<=15; j++){
    cout <<"(assert (= (w_A a"<<j<<"_"<<i<<") (bvadd (concat (_ bv0 15) pon"<<j<<"_"<<i<<") (bvadd (concat (_ bv0 15) ptw"<<j<<"_"<<i<<") (concat (_ bv0 15) pth"<<j<<"_"<<i<<")))))"<<endl;
  }}

  for(int i=0; i<T; i++){
  for(int j=0; j<=15; j++){
    cout <<"(assert (= (w_A a"<<j<<"_"<<i<<") (w_A b"<<j<<"_"<<i<<")))"<< endl;
  }}
  //----------------bit shuffle-----------------//
  for(int i=0; i<T; i++){
    cout <<"(assert (= a15_"<<i+1<<" (bvxor key15_"<<i<<" (shuffle b12_"<<i<<" b15_"<<i<<" b14_"<<i<<" b13_"<<i<<"))))"<< endl;
    cout <<"(assert (= a14_"<<i+1<<" (bvxor key14_"<<i<<" (shuffle b8_"<<i<<" b11_"<<i<<" b10_"<<i<<" b9_"<<i<<"))))"<< endl;
    cout <<"(assert (= a13_"<<i+1<<" (bvxor key13_"<<i<<" (shuffle b4_"<<i<<" b7_"<<i<<" b6_"<<i<<" b5_"<<i<<"))))"<< endl;
    cout <<"(assert (= a12_"<<i+1<<" (bvxor key12_"<<i<<" (shuffle b0_"<<i<<" b3_"<<i<<" b2_"<<i<<" b1_"<<i<<"))))"<< endl;
    cout <<"(assert (= a11_"<<i+1<<" (bvxor key11_"<<i<<" (shuffle b13_"<<i<<" b12_"<<i<<" b15_"<<i<<" b14_"<<i<<"))))"<< endl;
    cout <<"(assert (= a10_"<<i+1<<" (bvxor key10_"<<i<<" (shuffle b9_"<<i<<" b8_"<<i<<" b11_"<<i<<" b10_"<<i<<"))))"<< endl;
    cout <<"(assert (= a9_"<<i+1<<" (bvxor key9_"<<i<<" (shuffle b5_"<<i<<" b4_"<<i<<" b7_"<<i<<" b6_"<<i<<"))))"<< endl;
    cout <<"(assert (= a8_"<<i+1<<" (bvxor key8_"<<i<<" (shuffle b1_"<<i<<" b0_"<<i<<" b3_"<<i<<" b2_"<<i<<"))))"<< endl;
    cout <<"(assert (= a7_"<<i+1<<" (bvxor key7_"<<i<<" (shuffle b14_"<<i<<" b13_"<<i<<" b12_"<<i<<" b15_"<<i<<"))))"<< endl;
    cout <<"(assert (= a6_"<<i+1<<" (bvxor key6_"<<i<<" (shuffle b10_"<<i<<" b9_"<<i<<" b8_"<<i<<" b11_"<<i<<"))))"<< endl;
    cout <<"(assert (= a5_"<<i+1<<" (bvxor key5_"<<i<<" (shuffle b6_"<<i<<" b5_"<<i<<" b4_"<<i<<" b7_"<<i<<"))))"<< endl;
    cout <<"(assert (= a4_"<<i+1<<" (bvxor key4_"<<i<<" (shuffle b2_"<<i<<" b1_"<<i<<" b0_"<<i<<" b3_"<<i<<"))))"<< endl;
    cout <<"(assert (= a3_"<<i+1<<" (bvxor key3_"<<i<<" (shuffle b15_"<<i<<" b14_"<<i<<" b13_"<<i<<" b12_"<<i<<"))))"<< endl;
    cout <<"(assert (= a2_"<<i+1<<" (bvxor key2_"<<i<<" (shuffle b11_"<<i<<" b10_"<<i<<" b9_"<<i<<" b8_"<<i<<"))))"<< endl;
    cout <<"(assert (= a1_"<<i+1<<" (bvxor key1_"<<i<<" (shuffle b7_"<<i<<" b6_"<<i<<" b5_"<<i<<" b4_"<<i<<"))))"<< endl;
    cout <<"(assert (= a0_"<<i+1<<" (bvxor key0_"<<i<<" (shuffle b3_"<<i<<" b2_"<<i<<" b1_"<<i<<" b0_"<<i<<"))))"<< endl;
  }

  //----------------key update-----------------//
  for(int i=0; i<T-4; i++){
    cout <<"(assert (= k0_"<<i+4<<" ((_ rotate_right 12) k0_"<<i<<")))"<< endl;
    cout <<"(assert (= k1_"<<i+4<<" ((_ rotate_right 2) k1_"<<i<<")))"<< endl;
  }
  for(int i=0; i<T; i++){
  for(int j=0; j<=15; j++){
    cout << "(assert (= key"<<j<<"_"<<i<<" (concat #b00 (concat ((_ extract "<<j<<" "<<j<<") k1_"<<i<<") ((_ extract "<<j<<" "<<j<<") k0_"<<i<<") ))))" << endl;
  }}
  //----------------bounds-----------------//

  cout << "(assert (= weight1 ";
  for(int i=0; i<T; i++){
  for(int j=0; j<=15; j++){
    if((i+1==T) && (j==15)) cout << "(concat (_ bv0 15) pon15_"<<T-1<<")";
    else cout << "(bvadd (concat (_ bv0 15) pon"<<j<<"_"<<i<<") ";
  }}
  for(int i=0; i<T; i++){
  for(int j=0; j<=15; j++){
    cout <<")";
  }}
  cout << ")" <<endl;
  cout << "(assert (= weight2 ";
  for(int i=0; i<T; i++){
  for(int j=0; j<=15; j++){
    if((i+1==T) && (j==15)) cout << "(concat (_ bv0 15) ptw15_"<<T-1<<")";
    else cout << "(bvadd (concat (_ bv0 15) ptw"<<j<<"_"<<i<<") ";
  }}
  for(int i=0; i<T; i++){
  for(int j=0; j<=15; j++){
    cout <<")";
  }}
  cout << ")" <<endl;
  cout << "(assert (= weight3 ";
  for(int i=0; i<T; i++){
  for(int j=0; j<=15; j++){
    if((i+1==T) && (j==15)) cout << "(concat (_ bv0 15) pth15_"<<T-1<<")";
    else cout << "(bvadd (concat (_ bv0 15) pth"<<j<<"_"<<i<<") ";
  }}
  for(int i=0; i<T; i++){
  for(int j=0; j<=15; j++){
    cout <<")";
  }}
  cout << ")" <<endl;
//total weight 10*weight1 + 15*weight2 + 7*weight3  = 5*realbound
  cout <<"(assert (= (_ bv"<<bound<<" 16) (bvadd (bvmul #x000a weight1) (bvadd (bvmul #x000f weight2) (bvmul #x0007 weight3)))))"<<endl;

  /*cout << "(assert (= ";
  for(int i=0; i<T; i++){
  for(int j=0; j<=15; j++){
    if((i+1==T) && (j==15)) cout << "(w_A a15_"<<T-1<<")";
    else cout << "(bvadd (w_A a"<<j<<"_"<<i<<") ";
  }}
  for(int i=0; i<T; i++){
  for(int j=0; j<=15; j++){
    if((i+1==T) && (j==15))cout << " (_ bv"<<AS<<" 16))";
    else cout <<")";
  }}
  cout << ")" <<endl;*/


  cout <<"(check-sat)"<< endl;
  for(int i=0; i<T; i++){
    for(int j=0; j<=15; j++){cout << "(get-value (a"<<j<<"_"<<i<<"))" << "  ";}
    for(int j=0; j<=15; j++){cout << "(get-value (b"<<j<<"_"<<i<<"))" << "  ";}
    for(int j=0; j<=15; j++){cout << "(get-value (pon"<<j<<"_"<<i<<"))" << "  ";}
    for(int j=0; j<=15; j++){cout << "(get-value (ptw"<<j<<"_"<<i<<"))" << "  ";}
    for(int j=0; j<=15; j++){cout << "(get-value (pth"<<j<<"_"<<i<<"))" << "  ";}
    cout <<"(get-value (k0_"<<i<<"))"<< endl;
    cout <<"(get-value (k1_"<<i<<"))"<< endl;
  }
  for(int j=0; j<=15; j++){cout << "(get-value (a"<<j<<"_"<<T<<"))" << "  ";}
  cout << "(get-value (weight1))" << endl;
  cout << "(get-value (weight2))" << endl;
  cout << "(get-value (weight3))" << endl;
  cout <<"(exit)"<<endl;
return 0;
}
