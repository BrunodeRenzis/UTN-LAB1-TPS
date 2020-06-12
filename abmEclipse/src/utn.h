#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED
int utn_getChar(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);
int utn_getCadena(char *pAux,int limite,int reintentos,char* msj,char*msjError);
int isLetras(char*pAux);
int getCadena(char* pAux,int limite);
int validFloat(char str[]);
float inputValidFloat(char message[], int max);
void inputStr(char* msg, char* str);
int inputValidInt(char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int inputInt(char* cadena);
int esNumerico(char* cadena);
