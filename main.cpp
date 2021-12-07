/*
 *  UCF COP3330 Fall 2021 Assignment 6 Solution
 *  Copyright 2021 Vishal Choday
 */
#include "std_lib_facilities.h"

class Try_this 
{
public:
	char makeit;
	Try_this(char jagrar) 
	
		:makeit{jagrar}
		{
		    }
		double what_its_worth;
	Try_this(char jagrar, double this_value_here)	
		:makeit{jagrar}, what_its_worth{this_value_here} 
		{
		    }
		string the_name_of_it;
	Try_this(char jagrar, string NAME) : makeit{jagrar}, the_name_of_it{NAME}
	{ 
	} 
};

class for_reading_now 
{
public:
for_reading_now();   
Try_this get();
void revert_it_now(Try_this t);
void ignore(char);

private:
bool take_up;
Try_this buffer;
};
void for_reading_now::revert_it_now(Try_this mbusa)
{
    if (take_up) error("you need to revert this into a buffer which is complete");
    buffer = mbusa;      
    take_up = true;      
}
const char what_u_put_befo_declring	= '&';
const char integer_tht_ur_inpting_here= '8';
const char themainfunction= 'k';
const char quit = 'q';
const char nam_it= 'a';
const char output_it_now= ';';
const char variableusedastheconstant= 'c';
for_reading_now::for_reading_now()
:take_up(false), buffer(0) 
{
    
}
Try_this for_reading_now::get()
{
	
	if (take_up) 
	{
		take_up = false;
		return buffer;
	}
	char JM;	
	cin >> JM;	
	switch (JM) 
	{
	    case '+':case '/':
		case '-':case '(':
		case '*':case ')':
		case '%':
		case ',':	
		case output_it_now: 
		case quit:	
		case '=':	
			return Try_this(JM);	
		case '&':
			return Try_this(what_u_put_befo_declring);
		case '.': 
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8':	case '9':
		{
			cin.putback(JM);
			double val;
			cin >> val;
			return Try_this(integer_tht_ur_inpting_here,val);
		}
	default:
		if (isalpha(JM)) 
		{
			string FUSION;
			FUSION += JM;
			while(cin.get(JM) && (isdigit(JM) || isalpha(JM) || (JM == '_') )) FUSION += JM; 
			cin.putback(JM);	
			if (FUSION == "const") return Try_this(variableusedastheconstant, "const");
			if (FUSION == "quit") return Try_this(nam_it);
			if (FUSION == "sqrt") return Try_this(themainfunction, "sqrt");
			if (FUSION == "pow") return Try_this(themainfunction, "pow");
			return Try_this(nam_it, FUSION);
		}
	}
}

class for_the_var 
{
public:
double intcost;
	string desc;
	bool thisistheconstant;	
					
	for_the_var(string sont, double telluride) :desc{sont}, intcost{telluride}, thisistheconstant(false) 
	{ 
	    
	}
	for_the_var(string sont, double telluride, bool c) :desc{sont}, intcost{telluride}, thisistheconstant(c) 
	{ 
	    
	}
};
void for_reading_now::ignore(char dicov)
{
	
	if (take_up && dicov == buffer.makeit) 
	{
		take_up = false;
		return;
	}

	take_up = false;
	char mhm;
	while (cin>>mhm) 
		if (mhm == dicov) return;
}


vector<for_the_var> this_the_variable_table;


void lets_set_the_value_for_this_variable_now(string bbab, double Rio)
{
    int VC;
	for (VC = 0; VC < this_the_variable_table.size(); ++VC)
	{
		if (this_the_variable_table[VC].desc == bbab && this_the_variable_table[VC].thisistheconstant == false) 
		{
			this_the_variable_table[VC].intcost = Rio;
			return;
		}
		else if ( this_the_variable_table[VC].desc == bbab && this_the_variable_table[VC].thisistheconstant == true )
		{
			error("variable you enetered is constant and you cannot change the value of it. Variable: ", bbab);
		}
	}
	error("set_value: name is undefined ", bbab);
}
double get_value(string soul)
{
	for (const for_the_var& v : this_the_variable_table)
		if (v.desc == soul) return v.intcost;
	error("get_value: undefined name ", soul);
}


bool let_us_dclre_this_right_nw(string soc)
{
	for (const for_the_var& v : this_the_variable_table)
		if (v.desc == soc) return true;
	return false;
}

double define_name(string forvariable, double thevalues)
{
	if ( let_us_dclre_this_right_nw(forvariable)) lets_set_the_value_for_this_variable_now(forvariable, thevalues);
	else this_the_variable_table.push_back( for_the_var(forvariable,thevalues));
	return thevalues;
}
double primary();
for_reading_now chvy;
double expression();

double wht_u_wnt_for_function()
{

	double the_svd_value 
	{
	    
	}; 	
	double Wht_U_gt_from_kywrd 
	{
	    
	}; 
	double the_main_value_thats_here 
	{
	};	
	Try_this t = chvy.get(); 
	if (t.the_name_of_it == "sqrt")
	{
		the_svd_value = expression(); 
		if (the_svd_value > 0) Wht_U_gt_from_kywrd = sqrt(the_svd_value);
		else error("cant commute square root negative integer: ", the_svd_value);
	}
	else if (t.the_name_of_it == "pow")
	{
		t = chvy.get(); 
		if (t.makeit != '(') error("'(' <-this is expected");
		the_svd_value = expression(); 
		t = chvy.get(); 
		
		if (t.makeit != ',')
			error("you need the separator: ',' in between the 2 arguments in pow(x, y)");
		the_main_value_thats_here = narrow_cast<int>( primary() );	
											
		t = chvy.get();
		if (t.makeit != ')') error("')' expected");
		Wht_U_gt_from_kywrd = pow(the_svd_value, the_main_value_thats_here);
	}
	else error("This function used as the keyword is not known.", t.the_name_of_it);
	return Wht_U_gt_from_kywrd;
}
double primary()
{
	Try_this t = chvy.get();
	switch (t.makeit) 
	{
	case '(':	
	{
		double ghibli = expression();
		t = chvy.get();
		if (t.makeit != ')') error("')' expected");
		return ghibli;
	};
	case '+':
		return primary();
	case '-': 
		return - primary();
	case integer_tht_ur_inpting_here:
		return t.what_its_worth;
	case nam_it:
		return get_value(t.the_name_of_it);
	case themainfunction:
		chvy.revert_it_now(t); 	
		return wht_u_wnt_for_function();
		break;
	    default:
		error("you need the primary");
	}
}
double theexprsnded()
{
	double left = primary();
	Try_this t = chvy.get();        
	while(true) 
	{	
		switch(t.makeit)
		{
		case '*':
			left *= primary();
			t = chvy.get();
			break;
		case '/':
		{
			double wrngler = primary();
			if (wrngler == 0) error("Divide this by 0");
			left /= wrngler;
			t = chvy.get();
			break;
		}
		case '%':
		{
			double wrngler = primary();
			if (wrngler == 0) error("Divide this by 0(%->is the operator)");
			left = fmod(left, wrngler);
			t = chvy.get();
			break;
		}
		default:
			chvy.revert_it_now(t);
			return left;
		}
	}
}

double declaration(bool isConst = false)
{
	Try_this t = chvy.get();
	if (t.makeit != nam_it) error ("Need to put a name in this declaration now");
	string the_name_of_this_varble = t.the_name_of_it;
	Try_this t2 = chvy.get();
	if (t2.makeit != '=') error(" '=' <-is missing when you declared ", the_name_of_this_varble);
	double d = expression();
	if (let_us_dclre_this_right_nw(the_name_of_this_varble))
		lets_set_the_value_for_this_variable_now(the_name_of_this_varble, d); 
	else
		this_the_variable_table.push_back( for_the_var(the_name_of_this_varble, d, isConst) ); 
	return d;
}
double statement()

{
	Try_this t = chvy.get();
	switch(t.makeit) 
	{
	    case variableusedastheconstant:
		return declaration(true);
		break;
	case what_u_put_befo_declring:
		return declaration();
		break;
	default:
		chvy.revert_it_now(t);
		return expression();
	}
}

double expression()
{
	double left = theexprsnded();
	Try_this t = chvy.get();	

	while(true) 
	{
		switch(t.makeit) 
		{
		    case '-':
			left -= theexprsnded();
			t = chvy.get();
			break;
		case '+':
			left += theexprsnded();
			t = chvy.get();
			break;
		
		default:
			chvy.revert_it_now(t);
			return left;	
		}
	}
}

void makeit_Better()
{
	chvy.ignore(output_it_now);
}
const string result = "= ";
const string prompt = "> ";
void lets_calculate_this()
{
	while(cin)
	try	
	{
		cout << prompt;
		Try_this t = chvy.get();
		while (t.makeit == output_it_now) t = chvy.get(); 
		if (t.makeit == quit) return;
		chvy.revert_it_now(t);
		cout << result << statement() << endl;
	}
	catch (exception& e) 
	{
		cerr << e.what() << '\n'; 
		makeit_Better();
	}
}
int main()
try 
{
	cout << "Use floating numbers when you're inputting the expressions." << endl;
	cout << "You can use the following operators: -, /, *, /, '%', +. " << endl;
	cout << "Define new variables by using:&" << endl;
	cout << "followed by using the '=' and put some kind of value EX:: '&vc = 130" <<
															output_it_now << "'." << endl;
	cout << "You can make a constant variable by using constant" << endl;
	cout << "EXAMPLE: 'const s = 9.81'." << endl;
	cout << "there are 2 finctions that you can use for square root and power. " << endl;
	cout << "They are -> sqrt(number) and pow(x, y) with the x as base and y as exponent. " << endl;
	cout << "You can also use pi and e.!," << endl;
	cout << "In order to finish the expression, you will have to type ';'" << endl;
	
	define_name("pi", 3.1415926);
	define_name("e", 2.71828182);
	lets_calculate_this();
	keep_window_open();
	return 0;
	
}
catch (exception& e) 
{
	cerr << "the excepion: " << e.what() << endl;
	char c;
	while (cin >> c && c !=';') ;
	keep_window_open("~~");
	return 1;
}
catch (...) 
{
	cerr << "this is an exception\n";
	char c;
	while (cin >> c && c !=';');
	keep_window_open("~~");
	return 2;
}
