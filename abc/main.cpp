#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

class tv
{
	private:
		int state;
		int volume;
		int maxchannel;
		int channel;
		int mod;
		int input;
	public:
		friend class remote;
		tv(int s,int mc,int v,int c,int m,int i)
		{
			maxchannel=mc;
			state=s;
			volume=v;
			channel=c;
			mod=m;
			input=i;
		}
		void onoff(bool a)
		{
			state=a;
		}
		void vochange(int a)
		{
			if(state==0) return ;
			volume+=a;
			if(volume>20||volume<0)
			volume-=a;
		}
		void chchange(int a)
		{
			if(state==0) return ;
			channel+=a;
			if(channel>maxchannel||channel<=0)
			channel-=a;
		}
		void setchannel(int a)
		{
			channel=a;
		}
		void setmode()
		{
			if(state==0) return ;
			mod=mod==1?0:1;
		}
		void setinput()
		{
			if(state==0) return ;
			input=input==1?0:1;
		}
		void print()
		{
			string str1,str2,str3;
			if(state==1)
			str1="on ";
			else str1="off ";
			if(mod==1)
			str2=" Cable ";
			else str2=" Antenna ";
			if(input==1)
			str3="VCR";
			else str3="TV";cout<<str1<<volume<<' '<<channel<<str2<<str3<<endl;
		}
};
class remote
{
	private:
		int mode;
		public:
			remote(int m):mode(m){}
			void volup(tv &t) { t.vochange(1);}
			void voldown(tv &t) {t.vochange(-1);}
			void chanup(tv &t) {t.chchange(1);}
			void chandown(tv &t) {t.chchange(-1);}
			void setchannel(tv &t,int c)
			{
				t.setchannel(c);
			}
			void setmode(tv &t)
			{
				t.setmode();
			}
			void setinput(tv &t)
			{
				t.setinput();
			}
			void seton(tv &t)
			{
				t.state=t.state==1?0:1;
			}
};
int main()
{
	string a,b,c;
	int d,e;
	cin>>a>>d>>e>>b>>c;
	getchar();
	int i,j,k;
	if(a=="on")
	i=1;
	else i=0;
	if(b=="Cable")
	j=1;
	else j=0;
	if(c=="VCR")
	k=1;
	else k=0;
	tv t(i,50,d,e,j,k);
	string str;
	str.clear();
	char ch;
	ch=cin.get();
	remote r(1);
	while(ch!='\n')
	{
		if(ch!=' ')
		str.push_back(ch);
		else
		{
			if(str=="onoff")
			r.seton(t);
			else if(str=="volup")
			r.volup(t);
			else if(str=="voldown")
			r.voldown(t);
			else if(str=="chanup")
			r.chanup(t);
			else if(str=="chandown")
			r.chandown(t);
			else if(str=="set_mode")
			r.setmode(t);
			else if(str=="set_input")
			r.setinput(t);
			//cout<<str;
			str.clear();//t.print();
		}
		ch=cin.get();
	}
	        if(str=="onoff")
			r.seton(t);
			else if(str=="volup")
			r.volup(t);
			else if(str=="voldown")
			r.voldown(t);
			else if(str=="chanup")
			r.chanup(t);
			else if(str=="chandown")
			r.chandown(t);
			else if(str=="set_mode")
			r.setmode(t);
			else
			r.setinput(t);
			str.clear();
	t.print();
}
