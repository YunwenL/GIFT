#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>

using namespace std;
void print_ineqs(int a3, int a2, int a1, int a0, int b3, int b2, int b1, int b0, int c, int i, int j){
  int pos=0;
  int neg=0;
  if(a3>0) pos++;
  else if(a3<0)  neg++;
  if(a2>0) pos++;
  else if(a2<0)  neg++;
  if(a1>0) pos++;
  else if(a1<0)  neg++;
  if(a0>0) pos++;
  else if(a0<0)  neg++;
  if(b3>0) pos++;
  else if(b3<0)  neg++;
  if(b2>0) pos++;
  else if(b2<0)  neg++;
  if(b1>0) pos++;
  else if(b1<0)  neg++;
  if(b0>0) pos++;
  else if(b0<0)  neg++;
  if(c>0) pos++;
  else if(c<0)  neg++;   //determine how many bvadd to write
  int tmp=1; //count how many bvadd already write
  cout <<"(assert (bvuge ";

    if((a3>0)&&(tmp<pos)){
      if(a3==1) {cout << "(bvadd (concat #b0000000 ((_ extract "<<3<<" "<<3<<")a"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvadd (bvmul #x0"<<a3<<" (concat #b0000000 ((_ extract "<<3<<" "<<3<<")a"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    else if((a3>0)&&(tmp==pos)){
      if(a3==1) {cout << "(concat #b0000000 ((_ extract "<<3<<" "<<3<<")a"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvmul #x0"<<a3<<" (concat #b0000000 ((_ extract "<<3<<" "<<3<<")a"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    if((a2>0)&&(tmp<pos)){
      if(a2==1) {cout << "(bvadd (concat #b0000000 ((_ extract "<<2<<" "<<2<<")a"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvadd (bvmul #x0"<<a2<<" (concat #b0000000 ((_ extract "<<2<<" "<<2<<")a"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    else if((a2>0)&&(tmp==pos)){
      if(a2==1) {cout << "(concat #b0000000 ((_ extract "<<2<<" "<<2<<")a"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvmul #x0"<<a2<<" (concat #b0000000 ((_ extract "<<2<<" "<<2<<")a"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    if((a1>0)&&(tmp<pos)){
      if(a1==1) {cout << "(bvadd (concat #b0000000 ((_ extract "<<1<<" "<<1<<")a"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvadd (bvmul #x0"<<a1<<" (concat #b0000000 ((_ extract "<<1<<" "<<1<<")a"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    else if((a1>0)&&(tmp==pos)){
      if(a1==1) {cout << "(concat #b0000000 ((_ extract "<<1<<" "<<1<<")a"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvmul #x0"<<a1<<" (concat #b0000000 ((_ extract "<<1<<" "<<1<<")a"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    if((a0>0)&&(tmp<pos)){
      if(a0==1) {cout << "(bvadd (concat #b0000000 ((_ extract "<<0<<" "<<0<<")a"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvadd (bvmul #x0"<<a0<<" (concat #b0000000 ((_ extract "<<0<<" "<<0<<")a"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    else if((a0>0)&&(tmp==pos)){
      if(a0==1) {cout << "(concat #b0000000 ((_ extract "<<0<<" "<<0<<")a"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvmul #x0"<<a0<<" (concat #b0000000 ((_ extract "<<0<<" "<<0<<")a"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    if((b3>0)&&(tmp<pos)){
      if(b3==1) {cout << "(bvadd (concat #b0000000 ((_ extract "<<3<<" "<<3<<")b"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvadd (bvmul #x0"<<b3<<" (concat #b0000000 ((_ extract "<<3<<" "<<3<<")b"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    else if((b3>0)&&(tmp==pos)){
      if(b3==1) {cout << "(concat #b0000000 ((_ extract "<<3<<" "<<3<<")b"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvmul #x0"<<b3<<" (concat #b0000000 ((_ extract "<<3<<" "<<3<<")b"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    if((b2>0)&&(tmp<pos)){
      if(b2==1) {cout << "(bvadd (concat #b0000000 ((_ extract "<<2<<" "<<2<<")b"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvadd (bvmul #x0"<<b2<<" (concat #b0000000 ((_ extract "<<2<<" "<<2<<")b"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    else if((b2>0)&&(tmp==pos)){
      if(b2==1) {cout << "(concat #b0000000 ((_ extract "<<2<<" "<<2<<")b"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvmul #x0"<<b2<<" (concat #b0000000 ((_ extract "<<2<<" "<<2<<")b"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    if((b1>0)&&(tmp<pos)){
      if(b1==1) {cout << "(bvadd (concat #b0000000 ((_ extract "<<1<<" "<<1<<")b"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvadd (bvmul #x0"<<b1<<" (concat #b0000000 ((_ extract "<<1<<" "<<1<<")b"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    else if((b1>0)&&(tmp==pos)){
      if(b1==1) {cout << "(concat #b0000000 ((_ extract "<<1<<" "<<1<<")b"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvmul #x0"<<b1<<" (concat #b0000000 ((_ extract "<<1<<" "<<1<<")b"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    if((b0>0)&&(tmp<pos)){
      if(b0==1) {cout << "(bvadd (concat #b0000000 ((_ extract "<<0<<" "<<0<<")b"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvadd (bvmul #x0"<<b0<<" (concat #b0000000 ((_ extract "<<0<<" "<<0<<")b"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    else if((b0>0)&&(tmp==pos)){
      if(b0==1) {cout << "(concat #b0000000 ((_ extract "<<0<<" "<<0<<")b"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvmul #x0"<<b0<<" (concat #b0000000 ((_ extract "<<0<<" "<<0<<")b"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
  if(c>0) cout << "#x0"<< hex <<c;
  for(int s=1; s<pos; s++){cout <<")";}
  cout <<" ";    // write neg
    tmp=1;
    if((a3<0)&&(tmp<neg)){
      if(a3==-1) {cout << "(bvadd (concat #b0000000 ((_ extract "<<3<<" "<<3<<")a"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvadd (bvmul #x0"<<-a3<<" (concat #b0000000 ((_ extract "<<3<<" "<<3<<")a"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    else if((a3<0)&&(tmp==neg)){
      if(a3==-1) {cout << "(concat #b0000000 ((_ extract "<<3<<" "<<3<<")a"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvmul #x0"<<-a3<<" (concat #b0000000 ((_ extract "<<3<<" "<<3<<")a"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    if((a2<0)&&(tmp<neg)){
      if(a2==-1) {cout << "(bvadd (concat #b0000000 ((_ extract "<<2<<" "<<2<<")a"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvadd (bvmul #x0"<<-a2<<" (concat #b0000000 ((_ extract "<<2<<" "<<2<<")a"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    else if((a2<0)&&(tmp==neg)){
      if(a2==-1) {cout << "(concat #b0000000 ((_ extract "<<2<<" "<<2<<")a"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvmul #x0"<<-a2<<" (concat #b0000000 ((_ extract "<<2<<" "<<2<<")a"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    if((a1<0)&&(tmp<neg)){
      if(a1==-1) {cout << "(bvadd (concat #b0000000 ((_ extract "<<1<<" "<<1<<")a"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvadd (bvmul #x0"<<-a1<<" (concat #b0000000 ((_ extract "<<1<<" "<<1<<")a"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    else if((a1<0)&&(tmp==neg)){
      if(a1==-1) {cout << "(concat #b0000000 ((_ extract "<<1<<" "<<1<<")a"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvmul #x0"<<-a1<<" (concat #b0000000 ((_ extract "<<1<<" "<<1<<")a"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    if((a0<0)&&(tmp<neg)){
      if(a0==-1) {cout << "(bvadd (concat #b0000000 ((_ extract "<<0<<" "<<0<<")a"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvadd (bvmul #x0"<<-a0<<" (concat #b0000000 ((_ extract "<<0<<" "<<0<<")a"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    else if((a0<0)&&(tmp==neg)){
      if(a0==-1) {cout << "(concat #b0000000 ((_ extract "<<0<<" "<<0<<")a"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvmul #x0"<<-a0<<" (concat #b0000000 ((_ extract "<<0<<" "<<0<<")a"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    if((b3<0)&&(tmp<neg)){
      if(b3==-1) {cout << "(bvadd (concat #b0000000 ((_ extract "<<3<<" "<<3<<")b"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvadd (bvmul #x0"<<-b3<<" (concat #b0000000 ((_ extract "<<3<<" "<<3<<")b"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    else if((b3<0)&&(tmp==neg)){
      if(b3==-1) {cout << "(concat #b0000000 ((_ extract "<<3<<" "<<3<<")b"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvmul #x0"<<-b3<<" (concat #b0000000 ((_ extract "<<3<<" "<<3<<")b"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    if((b2<0)&&(tmp<neg)){
      if(b2==-1) {cout << "(bvadd (concat #b0000000 ((_ extract "<<2<<" "<<2<<")b"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvadd (bvmul #x0"<<-b2<<" (concat #b0000000 ((_ extract "<<2<<" "<<2<<")b"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    else if((b2<0)&&(tmp==neg)){
      if(b2==-1) {cout << "(concat #b0000000 ((_ extract "<<2<<" "<<2<<")b"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvmul #x0"<<-b2<<" (concat #b0000000 ((_ extract "<<2<<" "<<2<<")b"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    if((b1<0)&&(tmp<neg)){
      if(b1==-1) {cout << "(bvadd (concat #b0000000 ((_ extract "<<1<<" "<<1<<")b"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvadd (bvmul #x0"<<-b1<<" (concat #b0000000 ((_ extract "<<1<<" "<<1<<")b"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    else if((b1<0)&&(tmp==neg)){
      if(b1==-1) {cout << "(concat #b0000000 ((_ extract "<<1<<" "<<1<<")b"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvmul #x0"<<-b1<<" (concat #b0000000 ((_ extract "<<1<<" "<<1<<")b"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    if((b0<0)&&(tmp<neg)){
      if(b0==-1) {cout << "(bvadd (concat #b0000000 ((_ extract "<<0<<" "<<0<<")b"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvadd (bvmul #x0"<<-b0<<" (concat #b0000000 ((_ extract "<<0<<" "<<0<<")b"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
    else if((b0<0)&&(tmp==neg)){
      if(b0==-1) {cout << "(concat #b0000000 ((_ extract "<<0<<" "<<0<<")b"<<dec<<j<<"_"<<dec<<i<<")) ";}
      else {cout << "(bvmul #x0"<<-b0<<" (concat #b0000000 ((_ extract "<<0<<" "<<0<<")b"<<dec<<j<<"_"<<dec<<i<<"))) ";}
        tmp++;}
  if(c<0) cout << "#x0" <<hex <<(-c);
  for(int s=1; s<neg; s++){cout <<")";}
  cout <<"))"<<endl;
}


int main(int argc, char *argv[]){
  const int T = atoi(argv[1]);
  const int bound = atoi(argv[2]);
  cout << "(set-logic QF_ABV)" << endl;
  cout << "(set-info :smt-lib-version 2.5)" <<endl;
  cout << "(set-option :produce-models true)" <<endl;
  for(int i=0; i<T; i++){      //declare variables
  for(int j=0; j<=15; j++){
		cout << "(declare-fun a"<<j<<"_"<<i<<" () (_ BitVec 4)) ";
		cout << "(declare-fun b"<<j<<"_"<<i<<" () (_ BitVec 4)) ";
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
  cout << endl;
  cout <<"(define-fun w_A ((x (_ BitVec 4))) (_ BitVec 16)  (bvor (bvand (bvlshr (concat (_ bv0 12) x) #x0003) #x0001) (bvor (bvand (bvlshr (concat (_ bv0 12) x) #x0002) #x0001) (bvor (bvand (concat (_ bv0 12) x) #x0001) (bvand (bvlshr (concat (_ bv0 12) x) #x0001) #x0001))))) ;test if an sbox(4-bit) is active" << endl;
  cout <<"(define-fun shuffle ((x3 (_ BitVec 4)) (x2 (_ BitVec 4)) (x1 (_ BitVec 4)) (x0 (_ BitVec 4))) (_ BitVec 4) (concat ((_ extract 3 3)x3) (concat ((_ extract 2 2)x2) (concat ((_ extract 1 1)x1) ((_ extract 0 0)x0)))))"<< endl;
  //----------------sbox-----------------//   gift
  for(int i=0; i<T; i++){
  for(int j=0; j<=15; j++){
    print_ineqs(3,1,4,4,-2,0,-2,1,0,i,j);
    print_ineqs(-2,4,1,1,3,-2,3,1,0,i,j);
    print_ineqs(3,1,-1,-1,2,3,1,-1,0,i,j);
    print_ineqs(-2,-2,0,0,2,-1,-1,-1,5,i,j);
    print_ineqs(-1,1,-3,2,-1,0,-3,-3,8,i,j);
    print_ineqs(3,-2,-2,3,1,1,4,1,0,i,j);
    print_ineqs(0,3,-1,-1,2,3,-1,3,0,i,j);
    print_ineqs(2,-1,0,0,2,-1,1,2,0,i,j);
    print_ineqs(-1,1,2,2,0,0,2,-1,0,i,j);
    print_ineqs(-2,-2,1,-2,-1,1,2,1,5,i,j);
    print_ineqs(1,0,0,-1,1,0,-1,-1,2,i,j);
    print_ineqs(-2,-1,-1,2,0,0,-2,-1,5,i,j);
    print_ineqs(-1,-1,-2,-2,-1,-2,2,-1,8,i,j);
    print_ineqs(-1,1,2,-1,-2,-2,-2,1,6,i,j);
    print_ineqs(-2,1,-2,2,3,3,1,4,0,i,j);
    print_ineqs(0,2,1,2,0,-2,1,1,0,i,j);
    print_ineqs(-1,-1,2,-1,-2,2,2,-1,4,i,j);
    print_ineqs(1,-1,-1,-1,0,-1,-1,0,4,i,j);
    print_ineqs(1,-1,1,0,-1,1,-1,0,2,i,j);
    print_ineqs(-1,1,1,-1,-1,1,0,-1,3,i,j);
    print_ineqs(-1,-1,-1,0,-1,1,-1,1,4,i,j);
    print_ineqs(1,3,3,2,-1,-1,2,-1,0,i,j);
    print_ineqs(1,-1,-1,-2,1,-1,-2,-1,6,i,j);
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
  cout << "(assert (= ";
  for(int i=0; i<T; i++){
  for(int j=0; j<=15; j++){
    if((i+1==T) && (j==15)) cout << "(w_A a15_"<<T-1<<")";
    else cout << "(bvadd (w_A a"<<j<<"_"<<i<<") ";
  }}
  for(int i=0; i<T; i++){
  for(int j=0; j<=15; j++){
    if((i+1==T) && (j==15))cout << " (_ bv"<<bound<<" 16))";
    else cout <<")";
  }}
  cout << ")" <<endl;
  cout <<"(check-sat)"<< endl;
  for(int i=0; i<T; i++){
    for(int j=0; j<=15; j++){cout << "(get-value (a"<<j<<"_"<<i<<"))" << "  ";}
    for(int j=0; j<=15; j++){cout << "(get-value (b"<<j<<"_"<<i<<"))" << "  ";}
    cout <<"(get-value (k0_"<<i<<"))"<< endl;
    cout <<"(get-value (k1_"<<i<<"))"<< endl;
  }
  for(int j=0; j<=15; j++){cout << "(get-value (a"<<j<<"_"<<T<<"))" << "  ";}
  cout <<"(exit)"<<endl;
return 0;
}
