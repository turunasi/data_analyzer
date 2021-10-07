//���C�u�����A����w�b�_�̃C���N���[�h
#include	<stdlib.h>
#include	<math.h>
#include	"�萔�E�\���̒�`.h"	//����w�b�_
#include	"����֐���`.h"		//����w�b�_

//------------------------------------------------------------------------------------------------------------------------------------------
//FFT���|����֐�
//------------------------------------------------------------------------------------------------------------------------------------------
void FFT( st_kojiku *kojiku ){
	if(kojiku->check.check_filter01_1A==1){
		printf("\t\t�����O���ǈ��@1A");
		FFT_IFFT(	kojiku->data.wp1A.real,
			kojiku->data.wp1A.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}
	if(kojiku->check.check_filter02_1C==1){
		printf("�A1C");
		FFT_IFFT(	kojiku->data.wp1C.real,
			kojiku->data.wp1C.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}
	if(kojiku->check.check_filter03_1E==1){
		printf("�A1E");
		FFT_IFFT(	kojiku->data.wp1E.real,
			kojiku->data.wp1E.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}
	if(kojiku->check.check_filter04_2A==1){
		printf("�A2A");
		FFT_IFFT(	kojiku->data.wp2A.real,
			kojiku->data.wp2A.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}
	if(kojiku->check.check_filter05_2C==1){
		printf("�A2C");
		FFT_IFFT(	kojiku->data.wp2C.real,
			kojiku->data.wp2C.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}
	if(kojiku->check.check_filter06_2E==1){
		printf("�A2E");
		FFT_IFFT(	kojiku->data.wp2E.real,
			kojiku->data.wp2E.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}
	if(kojiku->check.check_filter07_3A==1){
		printf("�A3A");
		FFT_IFFT(	kojiku->data.wp3A.real,
			kojiku->data.wp3A.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}
	if(kojiku->check.check_filter08_3C==1){
		printf("�A3C");
		FFT_IFFT(	kojiku->data.wp3C.real,
			kojiku->data.wp3C.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}
	if(kojiku->check.check_filter09_3E==1){
		printf("�A3E\n");
		FFT_IFFT(	kojiku->data.wp3E.real,
			kojiku->data.wp3E.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}
	if(kojiku->check.check_filter10_pspr==1){
		printf("\t\t���\�È��㏸\n");
		FFT_IFFT(	kojiku->data.pspr.real,
			kojiku->data.pspr.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}
	if(kojiku->check.check_filter11_hwi==1){
		printf("\t\t�����iI�^�M���j\n");
		FFT_IFFT(	kojiku->data.hwi.real,
			kojiku->data.hwi.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}
	if(kojiku->check.check_filter12_ptpr==1){
		printf("\t\t���\�S���㏸\n");
		FFT_IFFT(	kojiku->data.ptpr.real,
			kojiku->data.ptpr.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}
	if(kojiku->check.check_filter13_averv==1){
		printf("\t\t���k�@�����ώ�����\n");
		FFT_IFFT(	kojiku->data.averv.real,
			kojiku->data.averv.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}
	if(kojiku->check.check_filter14_psi==1 || kojiku->check.check_filter20_phi_psi==1){
		printf("\t\t�S���㏸�W��\n");
		FFT_IFFT(	kojiku->data.psi.real,
			kojiku->data.psi.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}
	if(kojiku->check.check_filter13_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
		printf("\t\t�È��㏸�W��\n");
		FFT_IFFT(	kojiku->data.psi_s.real,
			kojiku->data.psi_s.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
		//printf("FFTseiatu%lf\n",kojiku->sens.kousei.P_1);
	}	
	if(kojiku->check.check_filter15_phi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_filter16_phi_spsi==1){
		printf("\t\t���ʌW��\n");
		FFT_IFFT(	kojiku->data.phi.real,
			kojiku->data.phi.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}
	if(kojiku->check.check_filter18_hwi2==1){
		printf("\t\t��������iI�^�M���j\n");
		FFT_IFFT(	kojiku->data.hwi2.real,
			kojiku->data.hwi2.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}
	if (kojiku->check.check_filter25_hwi3 == 1){
		printf("\t\t��������iI�^�M���j\n");
		FFT_IFFT(kojiku->data.hwi3.real,
			kojiku->data.hwi3.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}

	if(kojiku->check.check_filter18_hwi2==1){
		printf("\t\t���ʌW��_hwi2\n");
		FFT_IFFT(	kojiku->data.phi2.real,
			kojiku->data.phi2.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}
	if (kojiku->check.check_filter25_hwi3 == 1){
		printf("\t\t���ʌW��_hwi3\n");
		FFT_IFFT(	kojiku->data.phi3.real,
			kojiku->data.phi3.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}

	if (kojiku->check.check_rawdata31_hwsp1_v == 1) {
		printf("\t\tHwsp1_v......\n");
		FFT_IFFT(kojiku->data.hwsp1_v.real,
			kojiku->data.hwsp1_v.imag,
			kojiku->line.newline,kojiku->line.log2,1
			);
	}

	if (kojiku->check.check_rawdata32_hwsp1_alpha == 1) {
		printf("\t\tHwsp1_alpha......\n");
		FFT_IFFT(kojiku->data.hwsp1_alpha.real,
			kojiku->data.hwsp1_alpha.imag,
			kojiku->line.newline,kojiku->line.log2,1
			);
	}

	if (kojiku->check.check_rawdata33_hwsp1_vaxis == 1) {
		printf("\t\tHwsp1_vaxis......\n");
		FFT_IFFT(kojiku->data.hwsp1_vaxis.real,
			kojiku->data.hwsp1_vaxis.imag,
			kojiku->line.newline,kojiku->line.log2,1
			);
	}

	if (kojiku->check.check_rawdata34_hwsp1_vcir == 1) {
		printf("\t\tHwsp1_vcir......\n");
		FFT_IFFT(kojiku->data.hwsp1_vcir.real,
			kojiku->data.hwsp1_vcir.imag,
			kojiku->line.newline,kojiku->line.log2,1
			);
	}


	if (kojiku->check.check_rawdata35_ndvaxis1 == 1) {
		printf("\t\tHwsp1_ndvaxis......\n");
		FFT_IFFT(kojiku->data.hwsp1_ndvaxis.real,
			kojiku->data.hwsp1_ndvaxis.imag,
			kojiku->line.newline,kojiku->line.log2,1
			);
	}

	if (kojiku->check.check_rawdata36_ndvcir1 == 1) {
		printf("\t\tHwsp1_ndvcir......\n");
		FFT_IFFT(kojiku->data.hwsp1_ndvcir.real,
			kojiku->data.hwsp1_ndvcir.imag,
			kojiku->line.newline,kojiku->line.log2,1
			);
	}

	if (kojiku->check.check_rawdata37_2daverv1 == 1 ) {
		printf("\t\tHwsp1_2daverv......\n");
		FFT_IFFT(kojiku->data.hwsp1_twod_averv.real,
			kojiku->data.hwsp1_twod_averv.imag,
			kojiku->line.newline,kojiku->line.log2,1
			);
	}

	if (kojiku->check.check_rawdata38_2dphi1 == 1||kojiku->check.check_rawdata39_2dphi_psi1 == 1) {
		printf("\t\tHwsp1_2dphi......\n");
		FFT_IFFT(kojiku->data.hwsp1_twod_phi.real,
			kojiku->data.hwsp1_twod_phi.imag,
			kojiku->line.newline,kojiku->line.log2,1
			);
	}

	if (kojiku->check.check_rawdata41_hwsp2_v == 1) {
		printf("\t\tHwsp2_v......\n");
		FFT_IFFT(kojiku->data.hwsp2_v.real,
			kojiku->data.hwsp2_v.imag,
			kojiku->line.newline,kojiku->line.log2,1
			);
	}

	if (kojiku->check.check_rawdata42_hwsp2_alpha == 1) {
		printf("\t\tHwsp2_alpha......\n");
		FFT_IFFT(kojiku->data.hwsp2_alpha.real,
			kojiku->data.hwsp2_alpha.imag,
			kojiku->line.newline,kojiku->line.log2,1
			);
	}

	if (kojiku->check.check_rawdata43_hwsp2_vaxis == 1) {
		printf("\t\thwsp2_vaxis......\n");
		FFT_IFFT(kojiku->data.hwsp2_vaxis.real,
			kojiku->data.hwsp2_vaxis.imag,
			kojiku->line.newline,kojiku->line.log2,1
			);
	}

	if (kojiku->check.check_rawdata44_hwsp2_vcir == 1) {
		printf("\t\thwsp2_vcir......\n");
		FFT_IFFT(kojiku->data.hwsp2_vcir.real,
			kojiku->data.hwsp2_vcir.imag,
			kojiku->line.newline,kojiku->line.log2,1
			);
	}


	if (kojiku->check.check_rawdata45_ndvaxis2 == 1) {
		printf("\t\thwsp2_ndvaxis......\n");
		FFT_IFFT(kojiku->data.hwsp2_ndvaxis.real,
			kojiku->data.hwsp2_ndvaxis.imag,
			kojiku->line.newline,kojiku->line.log2,1
			);
	}

	if (kojiku->check.check_rawdata46_ndvcir2 == 1) {
		printf("\t\thwsp2_ndvcir......\n");
		FFT_IFFT(kojiku->data.hwsp2_ndvcir.real,
			kojiku->data.hwsp2_ndvcir.imag,
			kojiku->line.newline,kojiku->line.log2,1
			);
	}

	if (kojiku->check.check_rawdata47_2daverv2 == 1||kojiku->check.check_rawdata49_2dphi_psi2 == 1) {
		printf("\t\thwsp2_2daverv......\n");
		FFT_IFFT(kojiku->data.hwsp2_twod_averv.real,
			kojiku->data.hwsp2_twod_averv.imag,
			kojiku->line.newline,kojiku->line.log2,1
			);
	}

	if (kojiku->check.check_rawdata48_2dphi2 == 1) {
		printf("\t\thwsp2_2dphi......\n");
		FFT_IFFT(kojiku->data.hwsp2_twod_phi.real,
			kojiku->data.hwsp2_twod_phi.imag,
			kojiku->line.newline,kojiku->line.log2,1
			);
	}

	if(kojiku->check.check_filter51_ptank==1){
		printf("\t\t�^���N������È��㏸\n");
		FFT_IFFT(	kojiku->data.ptank.real,
			kojiku->data.ptank.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
	}

	if(kojiku->check.check_filter52_ptank_psi==1 ){
		printf("\t\t�^���N������È��㏸�W��\n");
		FFT_IFFT(	kojiku->data.ptank_psi.real,
			kojiku->data.ptank_psi.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			1
			);
		//printf("FFTseiatu%lf\n",kojiku->sens.kousei.P_1);
	}	

	//printf("FFT%lf\n",kojiku->sens.kousei.P_1);
}



//------------------------------------------------------------------------------------------------------------------------------------------
//IFFT���|����֐�
//------------------------------------------------------------------------------------------------------------------------------------------
void IFFT( st_kojiku *kojiku ){
	if(kojiku->check.check_filter01_1A==1){
		printf("\t\t�����O���ǈ��@1A");
		FFT_IFFT(	kojiku->data.wp1A.real,
			kojiku->data.wp1A.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}
	if(kojiku->check.check_filter02_1C==1){
		printf("�A1C");
		FFT_IFFT(	kojiku->data.wp1C.real,
			kojiku->data.wp1C.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}
	if(kojiku->check.check_filter03_1E==1){
		printf("�A1E");
		FFT_IFFT(	kojiku->data.wp1E.real,
			kojiku->data.wp1E.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}
	if(kojiku->check.check_filter04_2A==1){
		printf("�A2A");
		FFT_IFFT(	kojiku->data.wp2A.real,
			kojiku->data.wp2A.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}
	if(kojiku->check.check_filter05_2C==1){
		printf("�A2C");
		FFT_IFFT(	kojiku->data.wp2C.real,
			kojiku->data.wp2C.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}
	if(kojiku->check.check_filter06_2E==1){
		printf("�A2E");
		FFT_IFFT(	kojiku->data.wp2E.real,
			kojiku->data.wp2E.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}
	if(kojiku->check.check_filter07_3A==1){
		printf("�A3A");
		FFT_IFFT(	kojiku->data.wp3A.real,
			kojiku->data.wp3A.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}
	if(kojiku->check.check_filter08_3C==1){
		printf("�A3C");
		FFT_IFFT(	kojiku->data.wp3C.real,
			kojiku->data.wp3C.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}
	if(kojiku->check.check_filter09_3E==1){
		printf("�A3E\n");
		FFT_IFFT(	kojiku->data.wp3E.real,
			kojiku->data.wp3E.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}
	if(kojiku->check.check_filter10_pspr==1){
		printf("\t\t���\�È��㏸\n");
		FFT_IFFT(	kojiku->data.pspr.real,
			kojiku->data.pspr.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}
	if(kojiku->check.check_filter11_hwi==1){
		printf("\t\t�����iI�^�M���j\n");
		FFT_IFFT(	kojiku->data.hwi.real,
			kojiku->data.hwi.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}
	if(kojiku->check.check_filter12_ptpr==1){
		printf("\t\t���\�S���㏸\n");
		FFT_IFFT(	kojiku->data.ptpr.real,
			kojiku->data.ptpr.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}
	if(kojiku->check.check_filter13_averv==1){
		printf("\t\t���k�@�����ώ�����\n");
		FFT_IFFT(	kojiku->data.averv.real,
			kojiku->data.averv.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}
	if(kojiku->check.check_filter14_psi==1 || kojiku->check.check_filter20_phi_psi==1){
		printf("\t\t�S���㏸�W��\n");
		FFT_IFFT(	kojiku->data.psi.real,
			kojiku->data.psi.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}
	if(kojiku->check.check_filter13_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
		printf("\t\t�È��㏸�W��\n");
		FFT_IFFT(	kojiku->data.psi_s.real,
			kojiku->data.psi_s.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}
	if(kojiku->check.check_filter15_phi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_filter16_phi_spsi==1){
		printf("\t\t���ʌW��\n");
		FFT_IFFT(	kojiku->data.phi.real,
			kojiku->data.phi.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}
	if(kojiku->check.check_filter18_hwi2==1){
		printf("\t\t��������iI�^�M���j\n");
		FFT_IFFT(	kojiku->data.hwi2.real,
			kojiku->data.hwi2.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}
	if (kojiku->check.check_filter25_hwi3 == 1){
		printf("\t\t��������iI�^�M���j\n");
		FFT_IFFT(kojiku->data.hwi3.real,
			kojiku->data.hwi3.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}

	if(kojiku->check.check_filter18_hwi2==1){
		printf("\t\t���ʌW��\n");
		FFT_IFFT(	kojiku->data.phi2.real,
			kojiku->data.phi2.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}

	if(kojiku->check.check_filter25_hwi3==1){
		printf("\t\t���ʌW��\n");
		FFT_IFFT(	kojiku->data.phi3.real,
			kojiku->data.phi3.imag,
			kojiku->line.newline,
			kojiku->line.log2,
			0
			);
	}

	if (kojiku->check.check_rawdata31_hwsp1_v == 1) {
		printf("\t\tHwsp1_v......\n");
		FFT_IFFT(kojiku->data.hwsp1_v.real,
			kojiku->data.hwsp1_v.imag,
			kojiku->line.newline,kojiku->line.log2,0
			);
	}

	if (kojiku->check.check_rawdata32_hwsp1_alpha == 1) {
		printf("\t\tHwsp1_alpha......\n");
		FFT_IFFT(kojiku->data.hwsp1_alpha.real,
			kojiku->data.hwsp1_alpha.imag,
			kojiku->line.newline,kojiku->line.log2,0
			);
	}

	if (kojiku->check.check_rawdata33_hwsp1_vaxis == 1) {
		printf("\t\tHwsp1_vaxis......\n");
		FFT_IFFT(kojiku->data.hwsp1_vaxis.real,
			kojiku->data.hwsp1_vaxis.imag,
			kojiku->line.newline,kojiku->line.log2,0
			);
	}

	if (kojiku->check.check_rawdata34_hwsp1_vcir == 1) {
		printf("\t\tHwsp1_vcir......\n");
		FFT_IFFT(kojiku->data.hwsp1_vcir.real,
			kojiku->data.hwsp1_vcir.imag,
			kojiku->line.newline,kojiku->line.log2,0
			);
	}


	if (kojiku->check.check_rawdata35_ndvaxis1 == 1) {
		printf("\t\tHwsp1_ndvaxis......\n");
		FFT_IFFT(kojiku->data.hwsp1_ndvaxis.real,
			kojiku->data.hwsp1_ndvaxis.imag,
			kojiku->line.newline,kojiku->line.log2,0
			);
	}

	if (kojiku->check.check_rawdata36_ndvcir1 == 1) {
		printf("\t\tHwsp1_ndvcir......\n");
		FFT_IFFT(kojiku->data.hwsp1_ndvcir.real,
			kojiku->data.hwsp1_ndvcir.imag,
			kojiku->line.newline,kojiku->line.log2,0
			);
	}

	if (kojiku->check.check_rawdata37_2daverv1 == 1 ) {
		printf("\t\tHwsp1_2daverv......\n");
		FFT_IFFT(kojiku->data.hwsp1_twod_averv.real,
			kojiku->data.hwsp1_twod_averv.imag,
			kojiku->line.newline,kojiku->line.log2,0
			);
	}

	if (kojiku->check.check_rawdata38_2dphi1 == 1||kojiku->check.check_rawdata39_2dphi_psi1 == 1) {
		printf("\t\tHwsp1_2dphi......\n");
		FFT_IFFT(kojiku->data.hwsp1_twod_phi.real,
			kojiku->data.hwsp1_twod_phi.imag,
			kojiku->line.newline,kojiku->line.log2,0
			);
	}

	if (kojiku->check.check_rawdata41_hwsp2_v == 1) {
		printf("\t\tHwsp2_v......\n");
		FFT_IFFT(kojiku->data.hwsp2_v.real,
			kojiku->data.hwsp2_v.imag,
			kojiku->line.newline,kojiku->line.log2,0
			);
	}

	if (kojiku->check.check_rawdata42_hwsp2_alpha == 1) {
		printf("\t\tHwsp2_alpha......\n");
		FFT_IFFT(kojiku->data.hwsp2_alpha.real,
			kojiku->data.hwsp2_alpha.imag,
			kojiku->line.newline,kojiku->line.log2,0
			);
	}

	if (kojiku->check.check_rawdata43_hwsp2_vaxis == 1) {
		printf("\t\thwsp2_vaxis......\n");
		FFT_IFFT(kojiku->data.hwsp2_vaxis.real,
			kojiku->data.hwsp2_vaxis.imag,
			kojiku->line.newline,kojiku->line.log2,0
			);
	}

	if (kojiku->check.check_rawdata44_hwsp2_vcir == 1) {
		printf("\t\thwsp2_vcir......\n");
		FFT_IFFT(kojiku->data.hwsp2_vcir.real,
			kojiku->data.hwsp2_vcir.imag,
			kojiku->line.newline,kojiku->line.log2,0
			);
	}


	if (kojiku->check.check_rawdata45_ndvaxis2 == 1) {
		printf("\t\thwsp2_ndvaxis......\n");
		FFT_IFFT(kojiku->data.hwsp2_ndvaxis.real,
			kojiku->data.hwsp2_ndvaxis.imag,
			kojiku->line.newline,kojiku->line.log2,0
			);
	}

	if (kojiku->check.check_rawdata46_ndvcir2 == 1) {
		printf("\t\thwsp2_ndvcir......\n");
		FFT_IFFT(kojiku->data.hwsp2_ndvcir.real,
			kojiku->data.hwsp2_ndvcir.imag,
			kojiku->line.newline,kojiku->line.log2,0
			);
	}

	if (kojiku->check.check_rawdata47_2daverv2 == 1) {
		printf("\t\thwsp2_2daverv......\n");
		FFT_IFFT(kojiku->data.hwsp2_twod_averv.real,
			kojiku->data.hwsp2_twod_averv.imag,
			kojiku->line.newline,kojiku->line.log2,0
			);
	}

	if (kojiku->check.check_rawdata48_2dphi2 == 1||kojiku->check.check_rawdata49_2dphi_psi2 == 1) {
		printf("\t\thwsp2_2dphi......\n");
		FFT_IFFT(kojiku->data.hwsp2_twod_phi.real,
			kojiku->data.hwsp2_twod_phi.imag,
			kojiku->line.newline,kojiku->line.log2,0
			);
	}

	if(kojiku->check.check_filter51_ptank==1){
		printf("\t\t�^���N������È��㏸\n");
		FFT_IFFT(	kojiku->data.ptank.real,
			kojiku->data.ptank.imag,
			kojiku->line.newline,kojiku->line.log2,0
			);
	}

	if(kojiku->check.check_filter52_ptank_psi==1 ){
		printf("\t\t�^���N������È��㏸�W��\n");
		FFT_IFFT(	kojiku->data.ptank_psi.real,
			kojiku->data.ptank_psi.imag,
			kojiku->line.newline,kojiku->line.log2,0
			);
		//printf("FFTseiatu%lf\n",kojiku->sens.kousei.P_1);
	}	

}



//------------------------------------------------------------------------------------------------------------------------------------------
//�w����g������������֐�
//------------------------------------------------------------------------------------------------------------------------------------------
void Cut_Freq_All( st_kojiku *kojiku ){

	if(kojiku->check.check_filter01_1A==1){
		Cut_Freq(	kojiku->data.wp1A.real,
			kojiku->data.wp1A.imag,
			kojiku->freq.cut1,
			kojiku->freq.cut3,
			kojiku->line.newline
			);
	}
	if(kojiku->check.check_filter02_1C==1){
		Cut_Freq(	kojiku->data.wp1C.real,
			kojiku->data.wp1C.imag,
			kojiku->freq.cut1,
			kojiku->freq.cut3,
			kojiku->line.newline
			);
	}
	if(kojiku->check.check_filter03_1E==1){
		Cut_Freq(	kojiku->data.wp1E.real,
			kojiku->data.wp1E.imag,
			kojiku->freq.cut1,
			kojiku->freq.cut3,
			kojiku->line.newline
			);
	}
	if(kojiku->check.check_filter04_2A==1){
		Cut_Freq(	kojiku->data.wp2A.real,
			kojiku->data.wp2A.imag,
			kojiku->freq.cut1,
			kojiku->freq.cut3,
			kojiku->line.newline
			);
	}
	if(kojiku->check.check_filter05_2C==1){
		Cut_Freq(	kojiku->data.wp2C.real,
			kojiku->data.wp2C.imag,
			kojiku->freq.cut1,
			kojiku->freq.cut3,
			kojiku->line.newline
			);
	}
	if(kojiku->check.check_filter06_2E==1){
		Cut_Freq(	kojiku->data.wp2E.real,
			kojiku->data.wp2E.imag,
			kojiku->freq.cut1,
			kojiku->freq.cut3,
			kojiku->line.newline
			);
	}
	if(kojiku->check.check_filter07_3A==1){
		Cut_Freq(	kojiku->data.wp3A.real,
			kojiku->data.wp3A.imag,
			kojiku->freq.cut1,
			kojiku->freq.cut3,
			kojiku->line.newline
			);
	}
	if(kojiku->check.check_filter08_3C==1){
		Cut_Freq(	kojiku->data.wp3C.real,
			kojiku->data.wp3C.imag,
			kojiku->freq.cut1,
			kojiku->freq.cut3,
			kojiku->line.newline
			);
	}
	if(kojiku->check.check_filter09_3E==1){
		Cut_Freq(	kojiku->data.wp3E.real,
			kojiku->data.wp3E.imag,
			kojiku->freq.cut1,
			kojiku->freq.cut3,
			kojiku->line.newline
			);
	}
	if(kojiku->check.check_filter10_pspr==1){
		Cut_Freq(	kojiku->data.pspr.real,
			kojiku->data.pspr.imag,
			kojiku->freq.cut2,
			kojiku->freq.cut4,
			kojiku->line.newline
			);
	}
	if(kojiku->check.check_filter11_hwi==1){
		Cut_Freq(	kojiku->data.hwi.real,
			kojiku->data.hwi.imag,
			kojiku->freq.cut1,
			kojiku->freq.cut3,
			kojiku->line.newline
			);
	}
	if(kojiku->check.check_filter12_ptpr==1){
		Cut_Freq(	kojiku->data.ptpr.real,
			kojiku->data.ptpr.imag,
			kojiku->freq.cut2,
			kojiku->freq.cut4,
			kojiku->line.newline
			);
	}
	if(kojiku->check.check_filter13_averv==1){
		Cut_Freq(	kojiku->data.averv.real,
			kojiku->data.averv.imag,
			kojiku->freq.cut2,
			kojiku->freq.cut4,
			kojiku->line.newline
			);
	}
	if(kojiku->check.check_filter14_psi==1 || kojiku->check.check_filter20_phi_psi==1){
		Cut_Freq(	kojiku->data.psi.real,
			kojiku->data.psi.imag,
			kojiku->freq.cut2,
			kojiku->freq.cut4,
			kojiku->line.newline
			);
	}
	if(kojiku->check.check_filter13_spsi==1 || kojiku->check.check_filter16_phi_spsi==1){
		Cut_Freq(	kojiku->data.psi_s.real,
			kojiku->data.psi_s.imag,
			kojiku->freq.cut2,
			kojiku->freq.cut4,
			kojiku->line.newline
			);
	}
	if(kojiku->check.check_filter15_phi==1 || kojiku->check.check_filter20_phi_psi==1 || kojiku->check.check_filter16_phi_spsi==1){
		Cut_Freq(	kojiku->data.phi.real,
			kojiku->data.phi.imag,
			kojiku->freq.cut2,
			kojiku->freq.cut4,
			kojiku->line.newline
			);
	}
	if(kojiku->check.check_filter18_hwi2==1){
		Cut_Freq(	kojiku->data.hwi2.real,
			kojiku->data.hwi2.imag,
			kojiku->freq.cut1,
			kojiku->freq.cut3,
			kojiku->line.newline
			);
	}
	if (kojiku->check.check_filter25_hwi3 == 1){
		Cut_Freq(kojiku->data.hwi3.real,
			kojiku->data.hwi3.imag,
			kojiku->freq.cut1,
			kojiku->freq.cut3,
			kojiku->line.newline
			);
	}

	if(kojiku->check.check_filter18_hwi2==1){
		Cut_Freq(	kojiku->data.phi2.real,
			kojiku->data.phi2.imag,
			kojiku->freq.cut1,
			kojiku->freq.cut3,
			kojiku->line.newline
			);
	}

	if (kojiku->check.check_filter25_hwi3 == 1){
		Cut_Freq(	kojiku->data.phi3.real,
			kojiku->data.phi3.imag,
			kojiku->freq.cut2,
			kojiku->freq.cut4,
			kojiku->line.newline
			);
	}

	if(kojiku->check.check_position_sp==0||kojiku->check.check_position_sp==2){

		if (kojiku->check.check_rawdata31_hwsp1_v == 1) {
			//printf("\t\tHwsp1_v......\n");
			Cut_Freq(kojiku->data.hwsp1_v.real,
				kojiku->data.hwsp1_v.imag,
				kojiku->freq.cut2,kojiku->freq.cut4,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata32_hwsp1_alpha == 1) {
			//printf("\t\tHwsp1_alpha......\n");
			Cut_Freq(kojiku->data.hwsp1_alpha.real,
				kojiku->data.hwsp1_alpha.imag,
				kojiku->freq.cut2,kojiku->freq.cut4,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata33_hwsp1_vaxis == 1) {
			//printf("\t\tHwsp1_vaxis......\n");
			Cut_Freq(kojiku->data.hwsp1_vaxis.real,
				kojiku->data.hwsp1_vaxis.imag,
				kojiku->freq.cut2,kojiku->freq.cut4,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata34_hwsp1_vcir == 1) {
			//printf("\t\tHwsp1_vcir......\n");
			Cut_Freq(kojiku->data.hwsp1_vcir.real,
				kojiku->data.hwsp1_vcir.imag,
				kojiku->freq.cut2,kojiku->freq.cut4,kojiku->line.newline
				);
		}


		if (kojiku->check.check_rawdata35_ndvaxis1 == 1) {
			//printf("\t\tHwsp1_ndvaxis......\n");
			Cut_Freq(kojiku->data.hwsp1_ndvaxis.real,
				kojiku->data.hwsp1_ndvaxis.imag,
				kojiku->freq.cut2,kojiku->freq.cut4,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata36_ndvcir1 == 1) {
			//printf("\t\tHwsp1_ndvcir......\n");
			Cut_Freq(kojiku->data.hwsp1_ndvcir.real,
				kojiku->data.hwsp1_ndvcir.imag,
				kojiku->freq.cut2,kojiku->freq.cut4,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata37_2daverv1 == 1 ) {
			//printf("\t\tHwsp1_2daverv......\n");
			Cut_Freq(kojiku->data.hwsp1_twod_averv.real,
				kojiku->data.hwsp1_twod_averv.imag,
				kojiku->freq.cut2,kojiku->freq.cut4,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata38_2dphi1 == 1||kojiku->check.check_rawdata39_2dphi_psi1 == 1) {
			//printf("\t\tHwsp1_2dphi......\n");
			Cut_Freq(kojiku->data.hwsp1_twod_phi.real,
				kojiku->data.hwsp1_twod_phi.imag,
				kojiku->freq.cut2,kojiku->freq.cut4,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata41_hwsp2_v == 1) {
			//printf("\t\tHwsp2_v......\n");
			Cut_Freq(kojiku->data.hwsp2_v.real,
				kojiku->data.hwsp2_v.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata42_hwsp2_alpha == 1) {
			//printf("\t\tHwsp2_alpha......\n");
			Cut_Freq(kojiku->data.hwsp2_alpha.real,
				kojiku->data.hwsp2_alpha.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata43_hwsp2_vaxis == 1) {
			//printf("\t\thwsp2_vaxis......\n");
			Cut_Freq(kojiku->data.hwsp2_vaxis.real,
				kojiku->data.hwsp2_vaxis.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata44_hwsp2_vcir == 1) {
			//printf("\t\thwsp2_vcir......\n");
			Cut_Freq(kojiku->data.hwsp2_vcir.real,
				kojiku->data.hwsp2_vcir.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}


		if (kojiku->check.check_rawdata45_ndvaxis2 == 1) {
			//printf("\t\thwsp2_ndvaxis......\n");
			Cut_Freq(kojiku->data.hwsp2_ndvaxis.real,
				kojiku->data.hwsp2_ndvaxis.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata46_ndvcir2 == 1) {
			//printf("\t\thwsp2_ndvcir......\n");
			Cut_Freq(kojiku->data.hwsp2_ndvcir.real,
				kojiku->data.hwsp2_ndvcir.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata47_2daverv2 == 1) {
			//printf("\t\thwsp2_2daverv......\n");
			Cut_Freq(kojiku->data.hwsp2_twod_averv.real,
				kojiku->data.hwsp2_twod_averv.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata48_2dphi2 == 1||kojiku->check.check_rawdata49_2dphi_psi2 == 1) {
			//printf("\t\thwsp2_2dphi......\n");
			Cut_Freq(kojiku->data.hwsp2_twod_phi.real,
				kojiku->data.hwsp2_twod_phi.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

	}

	if(kojiku->check.check_position_sp!=0 && kojiku->check.check_position_sp!=2){

		if (kojiku->check.check_rawdata31_hwsp1_v == 1) {
			//printf("\t\tHwsp1_v......\n");
			Cut_Freq(kojiku->data.hwsp1_v.real,
				kojiku->data.hwsp1_v.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata32_hwsp1_alpha == 1) {
			//printf("\t\tHwsp1_alpha......\n");
			Cut_Freq(kojiku->data.hwsp1_alpha.real,
				kojiku->data.hwsp1_alpha.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata33_hwsp1_vaxis == 1) {
			//printf("\t\tHwsp1_vaxis......\n");
			Cut_Freq(kojiku->data.hwsp1_vaxis.real,
				kojiku->data.hwsp1_vaxis.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata34_hwsp1_vcir == 1) {
			//printf("\t\tHwsp1_vcir......\n");
			Cut_Freq(kojiku->data.hwsp1_vcir.real,
				kojiku->data.hwsp1_vcir.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}


		if (kojiku->check.check_rawdata35_ndvaxis1 == 1) {
			//printf("\t\tHwsp1_ndvaxis......\n");
			Cut_Freq(kojiku->data.hwsp1_ndvaxis.real,
				kojiku->data.hwsp1_ndvaxis.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata36_ndvcir1 == 1) {
			//printf("\t\tHwsp1_ndvcir......\n");
			Cut_Freq(kojiku->data.hwsp1_ndvcir.real,
				kojiku->data.hwsp1_ndvcir.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata37_2daverv1 == 1 ) {
			//printf("\t\tHwsp1_2daverv......\n");
			Cut_Freq(kojiku->data.hwsp1_twod_averv.real,
				kojiku->data.hwsp1_twod_averv.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata38_2dphi1 == 1||kojiku->check.check_rawdata39_2dphi_psi1 == 1) {
			//printf("\t\tHwsp1_2dphi......\n");
			Cut_Freq(kojiku->data.hwsp1_twod_phi.real,
				kojiku->data.hwsp1_twod_phi.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata41_hwsp2_v == 1) {
			//printf("\t\tHwsp2_v......\n");
			Cut_Freq(kojiku->data.hwsp2_v.real,
				kojiku->data.hwsp2_v.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata42_hwsp2_alpha == 1) {
			//printf("\t\tHwsp2_alpha......\n");
			Cut_Freq(kojiku->data.hwsp2_alpha.real,
				kojiku->data.hwsp2_alpha.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata43_hwsp2_vaxis == 1) {
			//printf("\t\thwsp2_vaxis......\n");
			Cut_Freq(kojiku->data.hwsp2_vaxis.real,
				kojiku->data.hwsp2_vaxis.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata44_hwsp2_vcir == 1) {
			//printf("\t\thwsp2_vcir......\n");
			Cut_Freq(kojiku->data.hwsp2_vcir.real,
				kojiku->data.hwsp2_vcir.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}


		if (kojiku->check.check_rawdata45_ndvaxis2 == 1) {
			//printf("\t\thwsp2_ndvaxis......\n");
			Cut_Freq(kojiku->data.hwsp2_ndvaxis.real,
				kojiku->data.hwsp2_ndvaxis.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata46_ndvcir2 == 1) {
			//printf("\t\thwsp2_ndvcir......\n");
			Cut_Freq(kojiku->data.hwsp2_ndvcir.real,
				kojiku->data.hwsp2_ndvcir.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata47_2daverv2 == 1) {
			//printf("\t\thwsp2_2daverv......\n");
			Cut_Freq(kojiku->data.hwsp2_twod_averv.real,
				kojiku->data.hwsp2_twod_averv.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

		if (kojiku->check.check_rawdata48_2dphi2 == 1||kojiku->check.check_rawdata49_2dphi_psi2 == 1) {
			//printf("\t\thwsp2_2dphi......\n");
			Cut_Freq(kojiku->data.hwsp2_twod_phi.real,
				kojiku->data.hwsp2_twod_phi.imag,
				kojiku->freq.cut1,kojiku->freq.cut3,kojiku->line.newline
				);
		}

	}

	if(kojiku->check.check_filter51_ptank==1){
		Cut_Freq(	kojiku->data.ptank.real,
			kojiku->data.ptank.imag,
			kojiku->freq.cut2,
			kojiku->freq.cut4,
			kojiku->line.newline
			);
	}

	if(kojiku->check.check_filter52_ptank_psi==1){
		Cut_Freq(	kojiku->data.ptank_psi.real,
			kojiku->data.ptank_psi.imag,
			kojiku->freq.cut2,
			kojiku->freq.cut4,
			kojiku->line.newline
			);
	}

}



//------------------------------------------------------------------------------------------------------------------------------------------
//�����̐�Βl�����߂�֐�
//------------------------------------------------------------------------------------------------------------------------------------------
double Abs_Imag(double x, double y){

	return( sqrt( x * x + y * y ) );
}


//------------------------------------------------------------------------------------------------------------------------------------------
//FFT�֐�
//------------------------------------------------------------------------------------------------------------------------------------------
void FFT_IFFT(double x_real[], double x_imag[], unsigned int N, unsigned int log_N, unsigned int sw){

	unsigned int		number_stage, stage;
	unsigned int		i, j, k, n, m, r, *index;
	double			a_real, a_imag, b_real, b_imag, c_real, c_imag, real, imag;

	number_stage = log_N;	//�o�^�t���C���Z�̒i����log2(�f�[�^��)

	//printf("%f %f %f %f\n\n", x_real[32766], x_imag[0], x_real[32767], x_imag[1]);

	//�o�^�t���C���Z
	for(stage=1 ; stage<=number_stage ; stage++){	//�o�^�t���C���Z�̒i��

		for(i=0 ; i<Pow2(stage-1) ; i++){	//�e�i�ɂ�����f�[�^�̃O���[�v��

			for(j=0 ; j<Pow2(number_stage-stage) ; j++){	//�e�i�̃O���[�v���ɂ�����f�[�^�̑g�ݍ��킹��

				n = Pow2(number_stage - stage + 1) * i + j;	//�f�[�^�ԍ�[n]��[m]��g�Ƃ��Čv�Z
				m = n + Pow2(number_stage - stage);			//�f�[�^�ԍ�[n]��[m]��g�Ƃ��Čv�Z

				r = Pow2(stage - 1) * j;	//��]�q�̎���

				a_real = x_real[n];
				a_imag = x_imag[n];
				b_real = x_real[m];
				b_imag = x_imag[m];
				c_real = cos((2.0*PI*r)/N);
				if( sw ){
					c_imag = -sin((2.0*PI*r)/N);
				}else{
					c_imag = +sin((2.0*PI*r)/N);
				}

				if(stage < number_stage){	//�ŏI�i�ȊO
					x_real[n] = a_real + b_real;
					x_imag[n] = a_imag + b_imag;
					x_real[m] = (a_real-b_real)*c_real - (a_imag-b_imag)*c_imag;
					x_imag[m] = (a_imag-b_imag)*c_real + (a_real-b_real)*c_imag;
				}
				else{	//�ŏI�i
					x_real[n] = a_real + b_real;
					x_imag[n] = a_imag + b_imag;
					x_real[m] = a_real - b_real;
					x_imag[m] = a_imag - b_imag;
				}
			}
		}
	}

	//�C���f�b�N�X�̕��ёւ��̂��߂̃e�[�u���쐬
	index = (unsigned int *)calloc(N, sizeof(unsigned int));
	for(stage=1; stage<=number_stage; stage++){
		for(i=0; i<Pow2(stage-1); i++){
			index[Pow2(stage - 1) + i] = index[i] + Pow2(number_stage - stage);
		}
	}

	//�C���f�b�N�X�̕��בւ�
	for(k=0 ; k<N ; k++){
		if(index[k]>k){
			real = x_real[index[k]];
			imag = x_imag[index[k]];
			x_real[index[k]] = x_real[k];
			x_imag[index[k]] = x_imag[k];
			x_real[k] = real;
			x_imag[k] = imag;
		}
	}

	free(index);


	if( !sw ){
		for(double *p=x_real; p<x_real+N; p++ ){
			*p /= (double)N;
		}
	}
}



//------------------------------------------------------------------------------------------------------------------------------------------
//�w����g������������֐�
//------------------------------------------------------------------------------------------------------------------------------------------
void Cut_Freq( double *x_real, double *x_imag, double cutfreq, double cutfreq2, unsigned int n_newline ){


	//�ϐ��錾------------------------------------------------------------------------------------
	unsigned int	n_array	= (unsigned int)( (double)n_newline * (double)cutfreq / SampFreq );
	unsigned int	n_array2= (unsigned int)( (double)n_newline * (double)cutfreq2 / SampFreq );
	double			*p1;
	double			*p2;


	//�G���[�΍�----------------------------------------------------------------------------------
	if( cutfreq >= SampFreq/2 ){
		printf("�J�b�g�I�t���g�����T���v�����O���g����1/2��菬�����Ȃ�悤�ɂ��Ă��������B\n");
		printf("�����I�����ĉ������B\n");
		while(1);
	}

	//�w�肳�ꂽ���g���ȏ���J�b�g-----------------------------------------------------------------
	for(	p1 = x_real + n_array,
		p2 = x_imag + n_array;
		p1 <= x_real + n_newline - n_array,
		p2 <= x_imag + n_newline - n_array;
	p1++,
		p2++){
			*p1	= 0.0;
			*p2	= 0.0;
	}
	//�w�肳�ꂽ���g���ȉ����J�b�g-----------------------------------------------------------------
	for(	p1 = x_real ,
		p2 = x_imag ;
		p1 <= x_real + n_array2 -1,
		p2 <= x_imag + n_array2 -1;
	p1++,
		p2++){
			*p1	= 0.0;
			*p2	= 0.0;
	}
	for(	p1 = x_real + n_newline - n_array2 +1,
		p2 = x_imag + n_newline - n_array2 +1;
		p1 <= x_real + n_newline ,
		p2 <= x_imag + n_newline ;
	p1++,
		p2++){
			*p1	= 0.0;
			*p2	= 0.0;
	}
}


//------------------------------------------------------------------------------------------------------------------------------------------
//�U���X�y�N�g�����v�Z����֐�
//------------------------------------------------------------------------------------------------------------------------------------------
void FFT_AmpSpec( st_kojiku *kojiku ){

	//�ϐ��錾---------------------------------------------------------------------------------------
	double	*p1;
	double	*p2;
	double	*p3;

	//�ϐ��錾---------------------------------------------------------------------------------------
	if(kojiku->check.check_FFTampspec01_1A==1){
		for(	p1 = kojiku->data.wp1A.abs,
			p2 = kojiku->data.wp1A.real,
			p3 = kojiku->data.wp1A.imag;
		p1 < kojiku->data.wp1A.abs  + kojiku->line.ampspec,
			p2 < kojiku->data.wp1A.real + kojiku->line.ampspec,
			p3 < kojiku->data.wp1A.imag + kojiku->line.ampspec;
		p1++,
			p2++,
			p3++ ){
				*p1 = Abs_Imag(	*p2, *p3 );
		}
	}
	if(kojiku->check.check_FFTampspec04_2A==1){
		for(	p1 = kojiku->data.wp2A.abs,
			p2 = kojiku->data.wp2A.real,
			p3 = kojiku->data.wp2A.imag;
		p1 < kojiku->data.wp2A.abs  + kojiku->line.ampspec,
			p2 < kojiku->data.wp2A.real + kojiku->line.ampspec,
			p3 < kojiku->data.wp2A.imag + kojiku->line.ampspec;
		p1++,
			p2++,
			p3++ ){
				*p1 = Abs_Imag(	*p2, *p3 );
		}
	}
	if(kojiku->check.check_FFTampspec07_3A==1){
		for(	p1 = kojiku->data.wp3A.abs,
			p2 = kojiku->data.wp3A.real,
			p3 = kojiku->data.wp3A.imag;
		p1 < kojiku->data.wp3A.abs  + kojiku->line.ampspec,
			p2 < kojiku->data.wp3A.real + kojiku->line.ampspec,
			p3 < kojiku->data.wp3A.imag + kojiku->line.ampspec;
		p1++,
			p2++,
			p3++ ){
				*p1 = Abs_Imag(	*p2, *p3 );
		}
	}
	if(kojiku->check.check_FFTampspec12_ptpr==1){
		for(	p1 = kojiku->data.ptpr.abs,
			p2 = kojiku->data.ptpr.real,
			p3 = kojiku->data.ptpr.imag;
		p1 < kojiku->data.ptpr.abs  + kojiku->line.ampspec,
			p2 < kojiku->data.ptpr.real + kojiku->line.ampspec,
			p3 < kojiku->data.ptpr.imag + kojiku->line.ampspec;
		p1++,
			p2++,
			p3++ ){
				*p1 = Abs_Imag(	*p2, *p3 );
		}
	}
	if(kojiku->check.check_FFTampspec11_hwi==1){
		for(	p1 = kojiku->data.hwi.abs,
			p2 = kojiku->data.hwi.real,
			p3 = kojiku->data.hwi.imag;
		p1 < kojiku->data.hwi.abs  + kojiku->line.ampspec,
			p2 < kojiku->data.hwi.real + kojiku->line.ampspec,
			p3 < kojiku->data.hwi.imag + kojiku->line.ampspec;
		p1++,
			p2++,
			p3++ ){
				*p1 = Abs_Imag(	*p2, *p3 );
		}
	}
	if(kojiku->check.check_FFTampspec18_hwi2==1){
		for(	p1 = kojiku->data.hwi2.abs,
			p2 = kojiku->data.hwi2.real,
			p3 = kojiku->data.hwi2.imag;
		p1 < kojiku->data.hwi2.abs  + kojiku->line.ampspec,
			p2 < kojiku->data.hwi2.real + kojiku->line.ampspec,
			p3 < kojiku->data.hwi2.imag + kojiku->line.ampspec;
		p1++,
			p2++,
			p3++ ){
				*p1 = Abs_Imag(	*p2, *p3 );
		}
	}
	if (kojiku->check.check_FFTampspec25_hwi3 == 1){
		for (p1 = kojiku->data.hwi3.abs,
			p2 = kojiku->data.hwi3.real,
			p3 = kojiku->data.hwi3.imag;
		p1 < kojiku->data.hwi3.abs + kojiku->line.ampspec,
			p2 < kojiku->data.hwi3.real + kojiku->line.ampspec,
			p3 < kojiku->data.hwi3.imag + kojiku->line.ampspec;
		p1++,
			p2++,
			p3++){
				*p1 = Abs_Imag(*p2, *p3);
		}
	}

	if (kojiku->check.check_FFTampspec33_hwsp1_vaxis == 1){
		for (p1 = kojiku->data.hwsp1_vaxis.abs,
			p2 = kojiku->data.hwsp1_vaxis.real,
			p3 = kojiku->data.hwsp1_vaxis.imag;
		p1 < kojiku->data.hwsp1_vaxis.abs + kojiku->line.ampspec,
			p2 < kojiku->data.hwsp1_vaxis.real + kojiku->line.ampspec,
			p3 < kojiku->data.hwsp1_vaxis.imag + kojiku->line.ampspec;
		p1++,
			p2++,
			p3++){
				*p1 = Abs_Imag(*p2, *p3);
		}
	}

	if (kojiku->check.check_FFTampspec34_hwsp1_vcir == 1){
		for (p1 = kojiku->data.hwsp1_vcir.abs,
			p2 = kojiku->data.hwsp1_vcir.real,
			p3 = kojiku->data.hwsp1_vcir.imag;
		p1 < kojiku->data.hwsp1_vcir.abs + kojiku->line.ampspec,
			p2 < kojiku->data.hwsp1_vcir.real + kojiku->line.ampspec,
			p3 < kojiku->data.hwsp1_vcir.imag + kojiku->line.ampspec;
		p1++,
			p2++,
			p3++){
				*p1 = Abs_Imag(*p2, *p3);
		}
	}

	if (kojiku->check.check_FFTampspec43_hwsp2_vaxis == 1){
		for (p1 = kojiku->data.hwsp2_vaxis.abs,
			p2 = kojiku->data.hwsp2_vaxis.real,
			p3 = kojiku->data.hwsp2_vaxis.imag;
		p1 < kojiku->data.hwsp2_vaxis.abs + kojiku->line.ampspec,
			p2 < kojiku->data.hwsp2_vaxis.real + kojiku->line.ampspec,
			p3 < kojiku->data.hwsp2_vaxis.imag + kojiku->line.ampspec;
		p1++,
			p2++,
			p3++){
				*p1 = Abs_Imag(*p2, *p3);
		}
	}

	if (kojiku->check.check_FFTampspec34_hwsp1_vcir == 1){
		for (p1 = kojiku->data.hwsp2_vcir.abs,
			p2 = kojiku->data.hwsp2_vcir.real,
			p3 = kojiku->data.hwsp2_vcir.imag;
		p1 < kojiku->data.hwsp2_vcir.abs + kojiku->line.ampspec,
			p2 < kojiku->data.hwsp2_vcir.real + kojiku->line.ampspec,
			p3 < kojiku->data.hwsp2_vcir.imag + kojiku->line.ampspec;
		p1++,
			p2++,
			p3++){
				*p1 = Abs_Imag(*p2, *p3);
		}
	}

}


//------------------------------------------------------------------------------------------------------------------------------------------
//�U���X�y�N�g���̎��g�������v�Z����֐�
//------------------------------------------------------------------------------------------------------------------------------------------
void Axis_AmpSpec( st_kojiku *kojiku ){

	//�ϐ��錾---------------------------------------------------------------------------------------
	unsigned int	i;
	double			*p;

	//���g�����̌v�Z---------------------------------------------------------------------------------
	for(	i = 0,
		p = kojiku->freq.axis_ampspec;
		i < kojiku->line.ampspec,
		p < kojiku->freq.axis_ampspec + kojiku->line.ampspec;
	i++,
		p++ ){
			*p = (double)i * SampFreq / (double)kojiku->line.newline;
	}
}