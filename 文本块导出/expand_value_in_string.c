//**************************************������ֵ�����滻**************************************
#pragma warning(disable:4996)
#include <stdlib.h>
#include<stdio.h>
#include "typeDef.h"
#include "unreference.h"
#include "value_calculate.h"

char char_ppu_to_unicode[0x100][16] = {
	"(00)",		"(01)",		"(02)",		"(03)",		"(04)",		"��",			"����",		"��",			"����",		"(ð��)",	"%",			"/",			"�`",			"..",		"�a",			"�b",
	".",			"��",			"��",			"��",			"��",			"(��1)",		"(��2)",		"|",			"(��3)",		"(����)",	"��",			"(����)",	"��",			"��",			"��",			"��",
	"0",			"1",			"2",			"3",			"4",			"5",			"6",			"7",			"8",			"9",			"A",			"B",			"C",			"D",			"E",			"F",
	"G",			"H",			"I",			"J",			"K",			"L",			"M",			"N",			"O",			"P",			"Q",			"R",			"S",			"T",			"U",			"V",
	"W",			"X",			"Y",			"Z",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",
	"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",
	"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",
	"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"Ŀ",			"ҹ",
	"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",
	"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",
	"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"���ˣ�",
	"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"Σ",			"��",			"��",			"��",
	"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"��",
	"־",			"��",			"˽",			"��",			"��",			"��",			"ס",			"��",			"��",			"С",			"��",			"��",			"��",			"��",			"��",			"������",
	"��",			"��",			"��",			"��",			"ȫ",			"��",			"��",			"֪",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"ͬ",
	"��",			"��",			"��",			"��",			"�k",			"��",			"��",			"��",			"��",			"��",			"��",			"��",			"(FC)",		"(FD)",		" ",	"(FF)"
};

char char_ppu_to_unicode_ba[0x100][16] = {
	[0x82] = "��",
	[0x55] = "��",		"��",		"��",		"��",		"��",		"��",		"��",		"��",		"��",		"��",		"��",		"��",		"��",		"��",		"��",
	[0x85] = "��",		"��",		"��",		"��",		"��",		"��",		"��",		"��",		"��",		"��",		"��",		"��",		"��",		"��",		"��",
	[0x69] = "��",		"��",		"��",		"��",		"��",
	[0x99] = "��",		"��",		"��",		"��",		"��"
};

char char_ppu_to_unicode_pa[0x100][16] = {
	[0x69] = "��",		"��",		"��",		"��",		"��",
	[0x99] = "��",		"��",		"��",		"��",		"��"
};

struct string block_to_string_ppu(int block) {												//�缶����
	int text_pointer = block_to_text_pointer(block);
	struct threeByte text = unreference_text_pointer(text_pointer);
	struct pointer_with_length string_ppu_pointer = text_to_string_pointer(text);
	struct string string_ppu = unreference_string_pointer(string_ppu_pointer);
	return string_ppu;
}

struct string sentance_number_to_block_string(unsigned int sentance_number) {	//�缶����
	int sentance_pointer = sentance_number_to_sentance_pointer(sentance_number);
	struct threeByte sentance = unreference_sentance_pointer(sentance_pointer);
	int block_string_pointer = sentance_to_block_string_pointer(sentance);
	struct string block_string = unreferernce_block_string_pointer(block_string_pointer);
	return block_string;
}

struct string string_ppu_to_unicode(struct string string_ppu) {
	struct string string_unicode = { .string = { 0 } };
	for (int i = 0; i < string_ppu.length; i++) {
		switch (string_ppu.string[i]) {
		case 0x0E:	//�����a
			i++;
			strcat(string_unicode.string, char_ppu_to_unicode_ba[string_ppu.string[i]]);
#ifdef printf("�ַ�������Ȼ������32, �ַ���ָ��Ϊ%x�Ŀ϶�������\n", string_pointer);
			if (strcmp(char_ppu_to_unicode_ba[string_ppu.string[i]], ""))printf("�в���ȷ������\n");
#endif // printf("�ַ�������Ȼ������32, �ַ���ָ��Ϊ%x�Ŀ϶�������\n", string_pointer);

			break;
		case 0x0F:	//�������b
			i++;
			strcat(string_unicode.string, char_ppu_to_unicode_pa[string_ppu.string[i]]);
#ifdef printf("�ַ�������Ȼ������32, �ַ���ָ��Ϊ%x�Ŀ϶�������\n", string_pointer);
			if (strcmp(char_ppu_to_unicode_ba[string_ppu.string[i]], ""))printf("�в���ȷ�İ�����\n");
#endif // printf("�ַ�������Ȼ������32, �ַ���ָ��Ϊ%x�Ŀ϶�������\n", string_pointer);
			break;
		case 0x00:	//�������ã������￨
			i++;
			break;
		default:
			strcat(string_unicode.string, char_ppu_to_unicode[string_ppu.string[i]]);
		}
	}
	return string_unicode;
}



struct string block_string_to_string_ppu(struct string block_string) {
	struct string string_ppu = { .string = {0},.length = 0 };
	for (int block_count = 0; block_count < block_string.length; block_count++) {
		if (IS_TRIPLE_BYTE(block_string.string[block_count])) {
			block_count += 2;
			continue;
		}
		if (IS_DOUBLE_BYTE(block_string.string[block_count]) && block_string.string[block_count] < 0x80) {
			block_count++;
			continue;
		}
		if (block_string.string[block_count] < 0x80) {
			struct string string_ppu_slice = block_to_string_ppu(block_string.string[block_count]);
			for (int i = 0; i < string_ppu_slice.length; i++) {
				string_ppu.string[string_ppu.length + i] = string_ppu_slice.string[i];
			}
			string_ppu.length += string_ppu_slice.length;
			continue;
		}
		if (block_string.string[block_count] >= 0x80) {
			int byte1 = block_string.string[block_count];
			int byte2 = block_string.string[++block_count];
			struct string string_ppu_slice = block_to_string_ppu((byte1 << 8) + byte2);
			for (int i = 0; i < string_ppu_slice.length; i++) {
				string_ppu.string[string_ppu.length + i] = string_ppu_slice.string[i];
			}
			string_ppu.length += string_ppu_slice.length;
			continue;
		}


	}

	return string_ppu;
}

