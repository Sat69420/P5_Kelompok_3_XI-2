#include<iostream> 
#include<string.h>
#include<windows.h>
#include<stdio.h>
#include<cmath>
using namespace std;
bool done_Loading = false;
bool done_Login = false;
bool def_Info = false;
bool done_Type1 = false;
bool done_Type2 = false;
bool done_Type3 = false;
bool new_Info = false;
bool new_Data3 = false;
bool exit_App = false;
string username, lamp3;
float t, p, l, statpo, intens, dur_on, p_rec, p_max, dur[3], chg[3], luas, nlam, watt, yd, e, const_Prec, const_Intens, yd3, e3, dur3[3], const_Prec3, const_Intens3, panel;
float kelvin(float t){
    float temp = (float)t + 273;
    return temp;
}
float area(float p, float l){
    float luas = ((float)p * (float)l);
    return luas;
}
void temps(){
    cout << "Enter the current air temperature: ";
    cin >> t;
    if(done_Type1 == true){
        if(t >= 0 && t < 20){
            p_max = 0.0000029306 * panel;
        }
        else if (t >= 20 && t < 30){
            p_max = 0.0000030306 * panel;
        } 
        else p_max = 0.0000032306 * panel;
        done_Type1 = false;
    }
    else if(done_Type2 == true){
        if(t >= 0 && t < 20) {
            p_max = 0.0000058611 * panel;
        }
        else if (t >= 20 && t < 30){
            p_max = 0.0000060611 * panel;
        } 
        else p_max = 0.0000064612 * panel;
        done_Type2 = false;
    }
    else if(done_Type3 == true){
        if(t >= 0 && t < 20){ 
            p_max = 0.0000029306 * 9 * panel;
        }
        else if (t >= 20 && t < 30) {
            p_max = 0.0000030306 * 9 * panel;
        } 
        else p_max = 0.0000032306 * 9 * panel;
        done_Type3 = false;
    }   
}
void process(){
    system("cls");
    temps();
    cout << "Enter the area of the garden (length and width): "; 
    cin >> p >> l;
    
    statpo = 0.0000000567;
    p_rec = statpo * const_Prec * kelvin(t);  
    intens = const_Intens / area(p,l);
    dur_on = p_max / p_rec;
   
    luas = area(p,l);
   
    nlam = (e * luas) / yd;
    watt = nlam * e;
    cout << endl;
    system("cls");
    cout << "========================================" << endl;   
    cout << "--- Garden Lamp Specs & Informations ---" << endl;
   
    cout << "Acceptable light power";
    cout << " = "<<p_rec<<" Watt" << endl << endl;
   
    cout << "Maximum producible intensity of light";
    cout << " = ";
    printf("%.1f", intens);
    cout << " Candela" << endl << endl;
   
    cout << "Charging duration with electricity" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "~ Charger " << chg[i] << " = " << dur[i] << " Hours" << endl;
    }
   
    cout << "\nDurability" << endl;
    cout << " = " << dur_on << " Hours" << endl;
   
    cout << "\nRecommended number of garden lamps" << endl;
    cout << " = " << round(nlam) << " lamps" << endl << endl;
    
    cout << "Maximum producible power" << endl;
    cout << " = "<<watt<<" Watt" << endl << endl;
    cout << "========================================" << endl << endl;
    system("pause");
}
void type1(){
    done_Type1 = true;
    system("cls");
    int process_Menu;
    yd = 210;
    e = 5.35;
    panel = 2;
    dur[0] = 2.08; dur[1] = 1.93; dur[2] = 1.67;
    chg[0] = 2.4; chg[1] = 2.6; chg[2] = 3.0; 
    const_Prec = 0.0196;
    const_Intens = 600;
    cout << "GL1-12.11.22" << endl;
    cout << "Inputted Power: 3.378 10^-07 Watt    Light Intensity: 2.58 Cd    Charging Duration: 2.1 upto 1.7 Hours" << endl;
    cout << "Durability: 18 Hours                 Maximum Power: 84.7 Watt" << endl << endl;
    cout << "GL1-12.11.22 Menu" << endl;
    cout << "1 - Manage Lamp" << endl;
    cout << "Please type 0-1: ";
    cin >> process_Menu;
    cout << endl;
    switch(process_Menu){
        case 1:
        process();
        break;
        default:
        break;
    }
}
void type2(){
    done_Type2 = true;
    system("cls");
    int process_Menu;
    yd = 420;
    e = 6;
    panel = 2;
    dur[0] = 2; dur[1] = 1.8; dur[2] = 1.5;
    chg[0] = 2.4; chg[1] = 2.6; chg[2] = 3.0; 
    const_Prec = 0.0392;
    const_Intens = 1200;
    cout << "GL2-12-15-22" << endl;
    cout << "Inputted Power: 6.801 10^-07 Watt    Light Intensity: 5.67 Cd    Charging Duration: 2 upto 1.5 Hours" << endl;
    cout << "Durability: 18 Hours                 Maximum Power: 18.1 Watt" << endl << endl;
    cout << "GL2-12-15-22 Menu" << endl;
    cout << "1 - Manage Lamp" << endl;
    cout << "Please type 0-1: ";
    cin >> process_Menu;
    cout << endl;
    switch(process_Menu){
        case 1:
        process();
        break;
        default:
        break;
    }
}
void data3(){
    statpo = 0.0000000567;
    if(new_Data3 == true){
        yd3 = yd;
        e3 = e;
        const_Prec = panel * 0.0196;
        const_Intens = panel * 600;
        const_Prec3 = const_Prec;
        const_Intens3 = const_Intens;
        dur[0] = 2;
        dur[1] = 1.8;
        dur[2] = 1.5;
        for(int i = 0; i < 3; i++){
            dur3[i] = dur[i];
        }
        const_Prec3 = const_Prec;
        const_Intens3 = const_Intens;
        new_Data3 = false;
    }
    else{
        yd = yd3;
        e = e3;
        for(int i = 0; i < 3; i++){
            dur[i] = dur3[i];
        }
        const_Prec = const_Prec3;
        const_Intens = const_Intens3;
    }
}
void config(){
    cout << "Enter your lamp data." << endl;
    cout << "Enter the outdoor lighting standarts (0-500): ";
    cin >> yd;
    cout << "Enter the lamp watt: ";
    cin >> e;
    cout << "Enter the number of solar panels: ";
    cin >> panel;
    cout << "Configuring " << lamp3;
    for(int i = 0; i < 3; i++){
        Sleep(500);
        cout << ".";
    }
    cout << endl;
    system("pause");
    system("cls");
    new_Data3 = true;
    data3();
}
void type3(){
    done_Type3 = true;
    system("cls");
    int process_Menu;
    if(new_Info == false){ 
        cout << "Enter your garden lamp name: ";
        cin >> lamp3;
        system("cls");
        new_Info = true;
        config();
    }       
    cout << lamp3 << " Menu" << endl;
    cout << "1 - Manage Lamp" << endl;
    cout << "2 - Reconfigure Lamp" << endl;
    cout << "Please type 0-2: ";
    cin >> process_Menu;
    cout << endl;
    switch(process_Menu){
        case 1:
        data3();
        process();
        break;
        case 2:
        new_Info = false;
        type3();
        break;
        default:
        break;
    }
}
void outro(){
    system("cls");
    cout << "Thank You For Using This App." << endl;
    Sleep(500);
    cout << "Have";
    Sleep(500);
    cout << " A";
    Sleep(500);
    cout << " Great";
    Sleep(500);
    cout << " Day";
    for(int i = 0; i < 3; i++){
        Sleep(500);
        cout << ".";
    }
}
void loading_Screen(){
    if(done_Loading == false){
        system("cls");
        for(int i = 0; i < 3; i++){
        if(i == 0) cout << "Loading";
        Sleep(500);
        cout << ".";
        Sleep(500);
        }
    system("cls");
    cout << "Welcome To My Garden Lamp" << endl;
    Sleep(500);
    cout << "\"The Most Reliable Garden Lamp Companion App\"" << endl;
    }
    done_Loading = true;
}
void login(){
    string pass;
    if(done_Login == false){
        Sleep(500);
        cout << "Please Enter Your Login Information." << endl;
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";
        cin >> pass;
    }
    done_Login = true;
}
void homepage(){
    system("cls");
    int menu;
    cout << "Welcome Back," << endl;
    cout << username << endl; 
    cout << "Looking for something? We're here to help." << endl;
    cout << "Homepage Menu" << endl;
    cout << "1 - Garden Lamp Information" << endl;
    cout << "Please type 0-1: ";
    cin >> menu;
    cout << endl;
    switch(menu){
        case 1:
        break;
        default:
        exit_App = true;
        break;
    }
}
void info(){
    system("cls");
    if(def_Info == true) cout << "Seems like we couldn't find what you're looking for." << endl;
    int lamp_Type; 
    if(exit_App == false){
        cout << "Please select your garden lamp type." << endl;
        cout << "1 - GL1-12.11.22" << endl;
        cout << "2 - GL2-12-15-22" << endl;
        if(new_Info == false) cout << "3 - Add new lamp" << endl;
        else cout << "3 - " << lamp3 << endl;
        cout << "Please type 0-3: ";
        cin >> lamp_Type;
        cout << endl;
        switch(lamp_Type){
            case 1:
            def_Info = false;
            type1();
            break;
            case 2:
            def_Info = false;
            type2();
            break;
            case 3:
            def_Info = false;
            type3();
            break;
            case 0:
            break;
            default:
            def_Info = true;
            info();
            break;
        }
    }
}
int main(){
    loading_Screen();
    login();
    homepage();
    info();
    if(exit_App == false){
        main();
    }
    else{
        outro();
    }
    return 0;
}