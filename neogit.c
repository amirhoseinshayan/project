#define _GNU_SOURCE

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
//amirhosein shayan//
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
//boooooooooooooooooooooooommmmmmmmmmmmmmmmmmmmmmmm
int check_kardan_neogit(){
    struct dirent *entry; char tmp_cwd[1000]; bool exists = false;
    DIR *dir =opendir(".");
    do {
        DIR *dir = opendir(".");
        if (dir == NULL) {
            perror("Error opening current directory");
            return 1;
        }
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".neogit") == 0){
                exists = true;
            }
        }
        if (exists){
            return 2;
        }
        closedir(dir);
        if (getcwd(tmp_cwd, sizeof(tmp_cwd)) == NULL) return 1;
        if (strcmp(tmp_cwd, "/") != 0) {
            if (chdir("..") != 0) return 1;
        }
    }while (strcmp(tmp_cwd, "/") != 0);
    return 0;
}
//boooooooooooooooooooooooooooooooommmmmmmmmmmmmmmmmmm
int config_order_whith_out_global(int a, char *b[]){
    char cwd[1000]; FILE *file_name;FILE *file_email; char user_name[30]; char user_emaile[30];
    perror("salam...");
    if (getcwd(cwd, sizeof(cwd)) == NULL) return 1;
    char tmp_cwd[1000];
    bool exists = false;
    struct dirent *entry;
    perror("salam...");
    if(check_kardan_neogit() == 2){
        chdir(".neogit");
        mkdir("config", 0755);
        chdir("config");
        perror("salam...");
        if (strcmp(b[2],"user.name") == 0){
            perror("salam...");
            file_name = fopen("username.txt", "w");
            strcpy(user_name,b[3]);
            fprintf(file_name,"%s",user_name);
        }
        else if (strcmp(b[2],"user.email") == 0){
            file_email = fopen("user_emaile.txt", "w");
            strcpy(user_emaile,b[3]);
            fprintf(file_email,"%s",user_emaile);
        }

    }
    if (check_kardan_neogit() == 0)
        return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int config_alias_global(int a, char *b[]){
    char dastoor[100];
    char esme_file[30];
    chdir("home/amirhosein-shayan");
    mkdir("alias",0755);
    chdir("alias");
    perror("salam...");
    FILE * file;
    sscanf(b[3],"alias.%s",esme_file); 
    perror("salam...");
    strcat(esme_file,".txt");
    file = fopen(esme_file,"w");
    strcpy(dastoor, b[4]);
    perror("salam...");
    fprintf(file,"%s",dastoor);
    fclose(file);
    return 0;
}
//boooooooooooooooooommmmmmmmmmmmmmmmmmmmmm
int config_alias_whithout_global(int a, char *b[]){//???????
    char dastoor[100];
    char esme_file[30];
    if (check_kardan_neogit() == 2){
        chdir(".neogit");
        /*if (chdir(".neogit") == 0){
            perror("vared shod");
            return 1;
        }*/
        mkdir("alias", 0755);
        chdir("alias");
        FILE * file;
        sscanf(b[2],"alias.%s",esme_file); 
        perror("salam...");
        strcat(esme_file,".txt");
        file = fopen(esme_file,"w");
        strcpy(dastoor,b[3]);
        perror("salam...");
        fprintf(file,"%s",dastoor);
        fclose(file);
    }
    if (check_kardan_neogit() == 0){
        perror("pleas make.neogit");
    }
    return 0;
}
//boooooooooooooooooommmmmmmmmmmmmmm
int do_configs_global(int a, char *b[]){
    FILE *file_name;FILE *file_email;
    char user_name[30];
    char user_emaile[30];
    char cwd[1000];
    if (getcwd(cwd,sizeof(cwd)) == NULL){
        fprintf(stdout,"file not found");
        return 1;
    }
    chdir("home/amrhosein-shayan");
    mkdir ("config", 0755);
    chdir("config");

    if ( a == 5 && strcmp(b[2],"-global") == 0){
        if ( strcmp(b[3],"user.name") == 0){
            file_name = fopen("username.txt", "w");
            strcpy(user_name,b[4]);
            fprintf(file_name,"%s",user_name);
            fclose(file_name);
        }
        else if (strcmp(b[3],"user.email") == 0){
            file_email = fopen("user_emaile.txt", "w");
            strcpy(user_emaile,b[3]);
            fprintf(file_email,"%s",user_emaile);
            fclose(file_email);
        }
    }
    return 0;
}
//boooooooooooooooooooooooooooooommmmmmmmmmmmmmmm
int do_init(){
    char cwd[1000];
    if (getcwd(cwd, sizeof(cwd)) == NULL) return 1;

    char tmp_cwd[1000];
    bool exists = false;
    struct dirent *entry;
    do {
        // find .neogit
        DIR *dir = opendir(".");
        if (dir == NULL) {
            perror("Error opening current directory");
            return 1;
        }
        // bray chek karadan file hay dakhel yek pooshe //
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".neogit") == 0)
                exists = true;
        }
        closedir(dir);
        if (getcwd(tmp_cwd, sizeof(tmp_cwd)) == NULL) return 1;
        if (strcmp(tmp_cwd, "/") != 0) {
            if (chdir("..") != 0) return 1;
        }
    } while (strcmp(tmp_cwd, "/") != 0);

    if (chdir(cwd) != 0) return 1;
    if (!exists) {
        if (mkdir(".neogit", 0755) != 0) return 1;
        //return create_configs("mohsen", "mohsenghasemi8156@gmail.com");
    } else {
        perror("neogit repository has already initialized");
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int do_add_yek_file(int a, char *b[]){
    struct dirent *vooroodi; char adres_ghablan[25];
    getcwd (adres_ghablan,sizeof(adres_ghablan));
    char esme_file[20]; char path_asli[20]; char comand[200];
    FILE * file;
    check_kardan_neogit();
    if (check_kardan_neogit() == 2){
        chdir(".neogit");
        mkdir("stage", 0755);
        chdir("stage");
        realpath(b[2] , path_asli);
        printf("%s\n" , path_asli);
        perror("salam...");

        if (realpath == NULL){
            perror("this file not exist");
            return 1;
        }else{
            perror("salam...");
        strcmp(esme_file, b[2]);
        printf("444%s\n", esme_file);
        perror("salam...");
        strcpy(comand,"cp "); strcat(comand,path_asli);strcat(comand," ");strcat(comand,esme_file);
        perror("salam...");
        printf("999%s\n",comand);
        system (comand);
        chdir(adres_ghablan);
        }
    }
    if (check_kardan_neogit() == 0){
        perror("please make .neogit ");
        return 1;
    }
    return 0;
}
/////////////////////////////////////////////////////////////////////////////
int do_add_foolder(int a, char *b[]){
    char esme_file[20]; char esme_foolder[20];char adres_ghablan[30];char path_asli[30]; char comand[200];
    check_kardan_neogit();
    getcwd (adres_ghablan,sizeof(adres_ghablan));
    if (check_kardan_neogit() == 2){
        chdir(".neogit");
        mkdir("stage", 0755);
        chdir("stage");
        sscanf(b[2],"%s/%s", esme_foolder, esme_file);
        realpath(esme_file, path_asli);
        if (realpath == NULL){
            perror("this file not exist");
            return 1;
        }
        else{
        mkdir(esme_foolder, 0755);
        chdir(esme_foolder);
        strcpy(comand,"cp "); strcat(comand,path_asli);strcat(comand," ");strcat(comand,esme_file);
        system (comand);
        chdir(adres_ghablan);
        }
    }
    return 0;
}
int do_reset(){
    

    return 0;

}
int do_log(){
    return 0;


}
int do_commit(){
    return 0;
}
int do_status(){

    return 0;
}
int do_branch(){
    return 0;
}
int main (int argc, char *argv[]){
    if (argc <= 1){
        perror("please enter a valid command");
        return 1;
    }
    if (strcmp(argv[1],"init") == 0){
        do_init();
    }
    if (strcmp(argv[1],"config") == 0 && strcmp(argv[2],"-global") == 0){
        do_configs_global(argc,argv);
    }
    if (strcmp(argv[1],"config") == 0 && argc == 4){
        config_order_whith_out_global(argc,argv);
    }
    if (strcmp(argv[1],"config") == 0 && strstr(argv[3],"alias.") != NULL && strcmp(argv[2],"-global") == 0){
        config_alias_global(argc,argv);
    }
    if (strcmp(argv[1],"config") == 0 && strstr(argv[2],"alias.") != NULL){
        config_alias_whithout_global(argc,argv);
    }
    if (strcmp(argv[1],"add") == 0){
        if (argc <= 2){
            fprintf (stdout, "pleas enter a valid comand");
        }
        else{
            do_add_yek_file(argc,argv);
        }
    }
    /*if (strcmp(argv[1],"reset") == 0){
        if (argc <= 2){
            fprintf(stdout,"pleas enter a valid comand");
        }
        do_reset();
    }
    if (strcmp(argv[1],"status") == 0){
        if (argc <= 1){
            fprintf(stdout,"pleas enter a valid comand");
        }
        do_status();
    }
    if (strcmp(argv[1],"commit") == 0){
        if (argc <= 3){
            fprintf(stdout,"pleas enter a valid comand");
        }
        do_commit();
    }
    if (strcmp(argv[1],"log") == 0){
        if (argc <= 1){
            fprintf(stdout, "please enter a valid command");
        }
        do_log();
    }
    if (strcmp(argv[1],"branch") == 0){
        if (argc <= 2){
            fprintf(stdout, "please enter a valid command");
        }
        do_branch();
    }
    if (strcmp(argv[1],"branch") == 0){
        if (argc <= 2){
            fprintf(stdout, "please enter a valid command");
        }
    }*/
}