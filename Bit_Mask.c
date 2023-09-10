#include <stdio.h> 
#include <stdint.h>

uint8_t GIO_HANG; // 0000 0000 
typedef enum {
    AO = 1 << 0, // 0000 0001 = 1
    QUAN = 1 << 1, // 0000 0010 = 2
    VAY = 1 << 2,  // 0000 0100 = 4
    DAM = 1 << 3,  // 0000 1000 = 8
    NHAN = 1 << 4,  // 0001 0000 = 16
    VONG_TAY = 1 << 5, // 0010 0000 = 32 
    GIAY = 1 << 6, //0100 0000 = 64
    TUI = 1 << 7 // 1000 0000 = 128
}DO_DUNG;

void ADD_GIO_HANG(uint8_t* P_GIO_HANG, DO_DUNG do_dung) {
    *P_GIO_HANG |= do_dung;   
}

void DELETE_ITEM (uint8_t* P_GIO_HANG, DO_DUNG do_dung) {
    *P_GIO_HANG &= ~do_dung;
}


void CHECK_ITEM(uint8_t P_GIO_HANG, DO_DUNG do_dung) {//1011 0010 , 0011 0011 , AO|QUAN|NHAN|VONG_TAY
    // 1011 0010
    printf("Kiem tra do dung: \n");
    if((do_dung & AO) && (P_GIO_HANG & AO)) {
        printf("co AO\n");
    } 
    else if ((do_dung & AO) && (P_GIO_HANG & ~AO)) {
        printf("chua co AO\n"); 
    }

    if((do_dung & QUAN) && (P_GIO_HANG & QUAN)) {
        printf("co QUAN\n"); 
    }
    else if ((do_dung & QUAN) && (P_GIO_HANG & ~QUAN)) {
        printf("chua co QUAN\n"); 
    }

    if((do_dung & VAY) && (P_GIO_HANG & VAY)) {
        printf("co VAY\n"); 
    }
    else if ((do_dung & VAY) && (P_GIO_HANG & ~VAY)) {
        printf("chua co VAY\n"); 
    }

    if((do_dung & DAM) && (P_GIO_HANG & DAM)) {
        printf("co DAM\n"); 
    }
    else if ((do_dung & DAM) && (P_GIO_HANG & ~DAM)) {
        printf("chua co DAM\n"); 
    }
    
    if((do_dung & NHAN) && (P_GIO_HANG & NHAN)) {
        printf("co NHAN\n"); 
    }
    else if ((do_dung & NHAN) && (P_GIO_HANG & ~NHAN)) {
        printf("chua co NHAN\n"); 
    }

    if((do_dung & VONG_TAY) && (P_GIO_HANG & VONG_TAY)) {
        printf("co VONG TAY\n"); 
    }
    else if ((do_dung & VONG_TAY) && (P_GIO_HANG & ~VONG_TAY)) {
        printf("chua co VONG TAY\n"); 
    }

    if((do_dung &  GIAY) && (P_GIO_HANG & GIAY)) {
        printf("co GIAY\n"); 
    }
    else if ((do_dung &  GIAY) && (P_GIO_HANG & ~GIAY)) {
        printf("chua co GIAY\n"); 
    }

    if((do_dung & TUI) && (P_GIO_HANG & TUI)) {
        printf("co TUI\n"); 
    }
    else if ((do_dung & TUI) && (P_GIO_HANG & ~TUI)) {
        printf("chua co TUI\n"); 
    }
}

void SHOW_ITEM(uint8_t P_GIO_HANG) {
    printf("Danh sach san pham duoc chon: \n");
    if(P_GIO_HANG & AO) {
        printf("AO\n");
    }
    if(P_GIO_HANG & QUAN) {
        printf("QUAN\n");
    }
    if(P_GIO_HANG & VAY) {
        printf("VAY\n");
    }
    if(P_GIO_HANG & DAM) {
        printf("DAM\n");
    }
    if(P_GIO_HANG & NHAN) {
        printf("NHAN\n");
    }
    if(P_GIO_HANG & VONG_TAY) {
        printf("VONG_TAY\n");
    }
    if(P_GIO_HANG & GIAY) {
        printf("GIAY\n");
    }
    if(P_GIO_HANG & TUI) {
        printf("TUI\n");
    }
}


int main() {
    ADD_GIO_HANG(&GIO_HANG, TUI|AO|VONG_TAY); 
    CHECK_ITEM(GIO_HANG, TUI|AO|QUAN|VONG_TAY); 
    SHOW_ITEM(GIO_HANG);
}
