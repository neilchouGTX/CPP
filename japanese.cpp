#include <iostream>
#include <random>
#include <time.h>
#include <iomanip>
using namespace std;

int main(){
	string Hira[14][5]={{"あ","い","う","え","お"},{"か","き","く","け","こ"},{"さ","し","す","せ","そ"},
					{"た","ち","つ","て","と"},{"な","に","ぬ","ね","の"},{"は","ひ","ふ","へ","ほ"},
					{"ま","み","む","め","も"},{"ら","り","る","れ","ろ"},{"や","わ","ゆ","を","よ"},
					{"が","ぎ","ぐ","げ","ご"},{"ざ","じ","ず","ぜ","ぞ"},{"だ","ぢ","づ","で","ど"},
					{"ば","び","ぶ","べ","ぼ"},{"ぱ","ぴ","ぷ","ぺ","ぽ"}};
	string Kata[14][5]={{"ア","イ","ウ","エ","オ"},{"カ","キ","ク","ケ","コ"},{"サ","シ","ス","セ","ソ"},
					{"タ","チ","ツ","テ","ト"},{"ナ","ニ","ヌ","ネ","ノ"},{"ハ","ヒ","フ","ヘ","ホ"},
					{"マ","ミ","ム","メ","モ"},{"ラ","リ","ル","レ","ロ"},{"ヤ","ワ","ユ","ヲ","ヨ"},
					{"ガ","ギ","グ","ゲ","ゴ"},{"ザ","ジ","ズ","ゼ","ゾ"},{"ダ","ヂ","ヅ","デ","ド"},
					{"バ","ビ","ブ","ベ","ボ"},{"パ","ピ","プ","ペ","ポ"}}; 
	string roma[14][5]={{"a","i","u","e","o"},{"ka","ki","ku","ke","ko"},{"sa","shi","su","se","so"},
					{"ta","chi","tsu","te","to"},{"na","ni","nu","ne","no"},{"ha","hi","fu","he","ho"},
					{"ma","mi","mu","me","mo"},{"ra","ri","ru","re","ro"},{"ya","wa","yu","wo","yo"},
					{"ga","gi","gu","ge","go"},{"za","ji","zu","ze","zo"},{"da","di","du","de","do"},
					{"ba","bi","bu","be","bo"},{"pa","pi","pu","pe","po"}};
	int mode,times,score=0;
	int randomType, randomFirst, randomSecond;
	string ans;
	float scoreRate;
	srand(time(NULL));
	while(1==1){
		score = 0;
		for (int i=0; i<=40; i++)
			cout << "-";			
		cout << "\n請輸入你想練習的項目:\n1 平假名\n2 片假名\n3 平片混合\n4 退出\n";
		for (int i=0; i<=40; i++)
			cout << "-";
		cout << "\n請輸入:";
		cin >> mode;
		for (int i=0; i<=40; i++)
			cout << "-";
		if(mode == 4)
			break;
		cout << "\n\n\n\n";
		for (int i=0; i<=40; i++)
			cout << "-";
		cout << "\n請輸入你想做多少題目呢?\n";
		for (int i=0; i<=40; i++)
			cout << "-";
		cout << "\n請輸入:";
		cin >> times;
		for (int i=0; i<=40; i++)
			cout << "-";
		cout << "\n\n\n\n";
		
		if (mode == 1){
			cout <<"平假名練習\n";
			for(int i=1; i<=times; i++){
				randomFirst=rand()%14;
				randomSecond=rand()%5;
				for (int i=0; i<=40; i++)
					cout << "-";
				cout << endl << "第" << 	i << "題" << endl;
				cout << endl << Hira[randomFirst][randomSecond] << endl;
				cout << "\n請輸入羅馬拼音:";
				cin >> ans;
				if(roma[randomFirst][randomSecond] == ans){
					cout << "<答對了!>" << endl;
					score++;
				}
				else{
					cout << "<錯誤，正確拼音是 " << roma[randomFirst][randomSecond] << ">" << endl << endl; 
				}
				scoreRate = (float(score)/float(i))*100;
				cout << "答對題數:" << score << "   答對率:" <<  setprecision(4) << scoreRate<< "%" << endl;
				for (int i=0; i<=40; i++)
					cout << "-";
				cout << "\n\n\n";
			}	
		}
		else if(mode == 2){
			cout <<"片假名練習\n";
			for(int i=1; i<=times; i++){
				randomFirst=rand()%14;
				randomSecond=rand()%5;
				for (int i=0; i<=40; i++)
					cout << "-";
				cout << endl << "第" << 	i << "題" << endl;
				cout << endl << Kata[randomFirst][randomSecond] << endl;
				cout << "\n請輸入羅馬拼音:";
				cin >> ans;
				if(roma[randomFirst][randomSecond] == ans){
					cout << "<答對了!>" << endl;
					score++;
				}
				else{
					cout << "<錯誤，正確拼音是 " << roma[randomFirst][randomSecond] << ">" << endl << endl; 
				}
				scoreRate = (float(score)/float(i))*100;
				cout << "答對題數:" << score << "   答對率:" <<  setprecision(4) << scoreRate<< "%" << endl;
				for (int i=0; i<=40; i++)
					cout << "-";
				cout << "\n\n\n";
			}
		}
		else if (mode == 3){
			cout <<"平片混合練習\n";
			for(int i=1; i<=times; i++){
				randomType=rand()%2;
				randomFirst=rand()%14;
				randomSecond=rand()%5;
				for (int i=0; i<=40; i++)
					cout << "-";
				cout << endl << "第" << 	i << "題" << endl;
				if(randomType == 0)
					cout << endl << Hira[randomFirst][randomSecond] << endl;
				else
					cout << endl << Kata[randomFirst][randomSecond] << endl;
				cout << "\n請輸入羅馬拼音:";
				cin >> ans;
				if(roma[randomFirst][randomSecond] == ans){
					cout << "<答對了!>" << endl;
					score++;
				}
				else{
					cout << "<錯誤，正確拼音是 " << roma[randomFirst][randomSecond] << ">" << endl << endl; 
				}
				scoreRate = (float(score)/float(i))*100;
				cout << "答對題數:" << score << "   答對率:" <<  setprecision(4) << scoreRate<< "%" << endl;
				for (int i=0; i<=40; i++)
					cout << "-";
				cout << "\n\n\n";
			}
		}
		cout << endl << endl <<"本次總共答對:" << score << "/" << times << "   答對率:" <<  setprecision(4) << scoreRate<< "%" << endl << endl << endl << endl;

	}

	return 0;
}