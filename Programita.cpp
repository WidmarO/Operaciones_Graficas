#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

pair<float,float> a[50];
pair<float,float> centro1;
pair<float,float> b[50];
pair<float,float> centro2;
int pts = 0;

float rounder(float x){
	int a = x*1000;
	int num = x*100;
	if(a%10 >= 5){
		num++;
	}
	return (float)num/100.0;
}
void puntos(){

	cout << "cuantos puntos son?: ";
	cin >> pts; 
	cout << endl;
 	float x=0,y=0;
	for (int i=0 ; i<pts ; i++){
		cin >> x >> y;
		a[i].first = x;
		a[i].second = y;
		b[i].first = x;
		b[i].second = y;
	}
}
void ActCentros(){	
	centro1.first = 0; centro1.second = 0;
	centro2.first = 0; centro2.second = 0;
	for (int i=0 ; i<pts ; i++){
		centro1.first += a[i].first;
		centro1.second += a[i].second;
		centro2.first += b[i].first;
		centro2.second += b[i].second;
	}
	centro1.first = rounder(centro1.first/pts);
	centro1.second = rounder(centro1.second/pts);
	centro2.first = rounder(centro2.first/pts);
	centro2.second = rounder(centro2.second/pts);
	cout << "centro: "<< centro1.first << "  " << centro1.second << endl;
}	
/* #region Traslacion */
void TraslacionPtoRapida(float x , float y){
	//cout << "vector: " << x << "  " << y << endl; 
	for(int i=0 ; i<pts ; i++){
		a[i].first += x;
		a[i].second += y;	
		//cout << a[i].first << " " << a[i].second << endl;	
	}
	ActCentros();
}
void TraslacionOriRapida(){
	float x=centro1.first ,y=centro1.second;	
	for(int i=0 ; i<pts ; i++){
		a[i].first -= x;
		a[i].second -= y;		
	}
	ActCentros();	
}
void TraslacionPto(){
	cout << "Ingrese el vector de Traslacion: ";
	float x=0,y=0;
	cin >> x >> y; cout << endl;
	for(int i=0 ; i<pts ; i++){
		a[i].first += x;
		a[i].second += y;
		cout << a[i].first << "  " << a[i].second  << endl;
	}
	ActCentros();
}
void TraslacionOri(){
	cout << "Se traslado al origen" << endl;
	float x=centro1.first ,y=centro1.second;	
	for(int i=0 ; i<pts ; i++){
		a[i].first -= x;
		a[i].second -= y;
		cout << a[i].first << "  " << a[i].second  << endl;		
	}
	ActCentros();	
}
void Traslacion(){
	int op = 0;
	while(op <= 3){
	cout << "********* Traslacion *********\n";
	cout << "1) Traslacion a un punto\n";
	cout << "2) Traslacion al origen\n";
	cout << "3) Regresar a menu Principal\n";
	cout << "Ingrese opcion: ";
	cin >> op;
		if(op == 1){
			TraslacionPto();
		}
		if(op == 2){
			TraslacionOri();
		}
		if(op == 3){
			break;
		}
	}
}
/* #endregion Traslacion */
/* #region Rotacion */
void RotarMismoEje() {
	cout << "Rotacion en el mismo sitio" << endl;
	float gr = 0;
	cout << "grados a rotar: ";
	cin >> gr; cout << endl;
	gr = gr*(3.14159265358979323846/180);
	
	float aux1 = centro1.first, aux2 = centro1.second;
	float x=0,y=0;
	TraslacionPtoRapida(-aux1,-aux2);
	for(int i=0 ; i<pts ; i++){
		x = a[i].first; y = a[i].second;
		a[i].first = rounder(x * cos(gr) - y * sin(gr));
		a[i].second = rounder(x * sin(gr) + y * cos(gr));		
		//cout << a[i].first << "  " << a[i].second << endl;		
	}
	ActCentros();
	TraslacionPtoRapida(aux1,aux2);
	for(int i=0 ; i<pts ; i++){
		cout << a[i].first << "  " << a[i].second << endl;		
	}
	ActCentros();	
}
void RotarTraslacion(){
	cout << "Rotacion general" << endl;
	float gr = 0;
	cout << "grados a rotar: " << endl;
	cin >> gr; cout << endl;
	gr = gr*(3.14159/180);
	float x=0,y=0;
	for(int i=0 ; i<pts ; i++){
		x = a[i].first; y = a[i].second;
		a[i].first = rounder( x * cos(gr) - y * sin(gr));
		a[i].second = rounder(x * sin(gr) + y * cos(gr));
		cout << a[i].first << "  " << a[i].second << endl;		
	}
}
void PendGrados(){
	float num=0,den=0;
	cout << "Ingrese pendiente en fraccion\n Num: ";
	cin >> num; cout << "\n Den: "; cin >> den;
	float ans = atan(num/den);
	ans = ans*(180/3.141592);
	cout << "La pendiente " << num << "/" << den << endl;
	cout << "En grados hexadecimales es: " << ans << endl;
}
void Rotacion(){
	int op = 0;
	while(op <= 3){
	cout << "********* Rotacion *********\n";
	cout << "1) Rotacion sobre su eje\n";
	cout << "2) Rotacion en el mundo\n";
	cout << "3) Convertir pendiente en grados H\n";
	cout << "4) Regresar a menu Principal\n";
	cout << "Ingrese opcion: ";	
	cin >> op;
		if(op == 1){
			RotarMismoEje();
		}
		if(op == 2){
			RotarTraslacion();
		}
		if(op == 3){
			PendGrados();
		}
		if(op == 4){
			break;
		}
	}
}
/* #endregion Rotacion */
/* #region Reflexion */
void XReflexion(){
	for(int i=0 ; i<pts ; i++){
		//a[i].first += x;
		a[i].second = -a[i].second;
		cout << a[i].first << "  " << a[i].second  << endl;
	}
	ActCentros();
}
void YReflexion(){
	for(int i=0 ; i<pts ; i++){
		a[i].first = -a[i].first;
		//a[i].second = -a[i].second;
		cout << a[i].first << "  " << a[i].second  << endl;
	}
	ActCentros();
}
void Reflexion(){
	int op = 0;
	while(op <= 3){
	cout << "********* Reflexion *********\n";
	cout << "1) Reflexion eje x\n";
	cout << "2) Reflexion eje y\n";
	cout << "3) Regresar al menu\n";
	cout << "Ingrese opcion: ";	
	cin >> op;	
		if(op == 1){
			XReflexion();
		}
		if(op == 2){
			YReflexion();
		}
		if(op == 3){
			break;
		}
	}
}
/* #endregion Reflexion */
/* #region Reduccion */
void ReduccionG(){
	float aux1 = centro1.first, aux2 = centro1.second;
	float x=0,y=0;
	cout << "Reduccion en  (X , Y): ";
	cin >> x >> y; cout << endl;
	TraslacionOriRapida();
	for(int i=0 ; i<pts ; i++){
		a[i].first = rounder(a[i].first * x);
		a[i].second = rounder(a[i].second * y);		
	}
	ActCentros();
	TraslacionPtoRapida(aux1,aux2);
	for(int i=0 ; i<pts ; i++){
		cout << a[i].first << "  " << a[i].second << endl;		
	}
	ActCentros();
}
void Reduccion(){
	int op = 0;
	while(op <= 2){
	cout << "********* Reduccion *********\n";
	cout << "1) Reduccion General\n";
	cout << "2) Regresar al menu\n";
	cout << "Ingrese opcion: ";	
	cin >> op;
		if(op == 1){
			ReduccionG();
		}
		if(op == 2){
			break;
		}
	}
}
/* #endregion Reduccion */
void Restaurar(){
	pair<float,float> x;
	x.first = 0; x.second = 0;
	for(int i=0 ; i<pts ; i++){
		x = b[i];
		a[i] = x;
	}
	ActCentros();
}
void Redondear(){
	for(int i=0 ; i<pts ; i++){
		a[i].first = round(a[i].first);
		a[i].second = round(a[i].second);
		cout << a[i].first << "  " << a[i].second << endl;
	}
	ActCentros();
}
void menu(){
	int op = 0;
	while(op <= 5){
	cout << "===============================================" << endl;
	cout << "========= Programa para Comp Grafica ==========" << endl;
	cout << "===============================================\n" << endl;
	cout << "1) Rotacion" << endl;
	cout << "2) Traslacion" << endl;
	cout << "3) Reduccion" << endl;
	cout << "4) Reflexion" << endl;	
	cout << "5) Redondear pts a la unidad" << endl;
	cout << "6) Restaurar a pts iniciales" << endl;
	cout << "7) Reiniciar" << endl;
	cout << "Ingrese opcion: ";
	cin >> op; cout << endl;
		if(op == 1){
			Rotacion();
		}
		if(op == 2){
			Traslacion();
		}
		if(op == 3){
			Reduccion();
		}
		if(op == 4){
			Reflexion();
		}
		if(op == 5){
			Redondear();
		}
		if(op == 6){
			Restaurar();
		}
		if(op == 7){
			break;
		}
	}
}
int main(){
	while(true){
		puntos(); 
		ActCentros();
		menu();
	}	
}
