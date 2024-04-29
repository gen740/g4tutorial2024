//******************************************************************************
// クラスとは？：　C03_WhatIsClass.cc: 
//******************************************************************************
// [自習の進め方]
//    1) 以下のプログラムに書かれたコメントを順次読む
//    2) コメント部分に[問]と書かれた行では、そこに書かれた指示に従い、'?'文字部分を
//       正しい文に置き換える。
//    3) 全ての[問]に回答を終了したら、以下のc++コマンドを実行する
//         % c++ C03_WhatIsClass.cc
//       　　　　　[注]　使用c++のversionが古い場合、'-std=c++11'のオプションをつける
//    4) コンパイラ エラーが生じたら、エラー情報からコードを修正する
//    5) エラーが無くなり、実行ファイル（a.out）が作られたら、それを以下のように実行
//         % a.out
//       実行すると、main.ccに書いた'cout'の結果が出る
//    6) 適当なデバッグ文をコード中に挿入、各文の動作をチェックすることを薦める
//
//    (注)　自習問題の解答は以下のファイルにある：
//           ../Z_AnswersDir/C03_WhatIsClass_Ans.cc
//******************************************************************************

#include <iostream>
#include <string>
using namespace std;

//-----------------------------------------------------------------------------
// [課題 1] Rectangularクラスを作る
//-----------------------------------------------------------------------------

// Hands-onのスライドを参照し、[問]と書かれた行の「？」部分を書き換えて、クラスを完成させる
class Rectangular {                       // [問] classの宣言
  public:                                 // [問] publicメンバー定義 （データと関数）
    Rectangular( double x, double y ) {   // [問] constructor(classと同名の関数)の定義
      sizeX = x;
      sizeY = y;
    }          

    double area() {                       // 面積をdouble型で返す関数の定義
      return sizeX*sizeY; 
    }     

  private:                                // [問] privateメンバーの定義 （データと関数）
    double sizeX;
    double sizeY;                          
};

//-----------------------------------------------------------------------------
// [課題 2] Rectangularクラスを使う
//-----------------------------------------------------------------------------

// 以下の「？」部分を部分を書き換えて'main()'プログラムを完成させる
int main() {
  Rectangular rc{ 3.0, 4.0 };               // [問] Rectangular オブジェクト(rc)の生成
  cout << "Area:  " << rc.area()  << endl;  // [問] rcの'area()'関数をドット(.)で使え
}
