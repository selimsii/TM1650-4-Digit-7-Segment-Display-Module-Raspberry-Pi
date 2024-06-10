class roundProperly{
	public:
	double round(string str){
		if(isDot(str)){
			int pos=str.find(".");
			string floating="0."+str.substr(pos+1);
			string decimal=str.substr(0,pos);
			cout<<(stod(floating)+stod(decimal))<<endl;
			return (stod(decimal)+(stod(floating))+0.0001);
		}
		else {
			return stod(str);
		}
	}
	private:
	bool isDot(string str){
		return str.find(".")!=string::npos;
	}
};
