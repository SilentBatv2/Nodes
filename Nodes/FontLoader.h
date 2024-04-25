#pragma once
#include "stdafx.h"
#include <fstream>
#include <unordered_map>


struct tex_dat
{
	unsigned int x, y, width, height, x_offset, y_offset, x_advance;
};

static bool loadFont(std::unordered_map<int, tex_dat> &data, std::string path)
{
	std::ifstream inputFile(path);

	if (!inputFile.is_open()) {
		QMessageBox::critical(nullptr, "Failed to load Font", "failed to load .fnt file from resources");
		return false;
	}

	char temp;
	char val[5];
	unsigned int id;
	tex_dat temp_dat;

	int state = 0, count_lines = 0, line_no = 0;

	while (inputFile.get(temp)) {
		if (count_lines < 4)
		{
			if (temp == '\n')
			{
				++count_lines;
				continue;
			}
			else
			{
				continue;
			}
		}

		if (temp == '=')
		{
			inputFile.getline(val, 4, ' ');
			switch (state)
			{
			case 0:
				id = atoi(val);
				++state;
				break;
			case 1:
				temp_dat.x = atoi(val);
				++state;
				break;
			case 2:
				temp_dat.y = atoi(val);
				++state;
				break;
			case 3:
				temp_dat.width = atoi(val);
				++state;
				break;
			case 4:
				temp_dat.height = atoi(val);
				++state;
				break;
			case 5:
				temp_dat.x_offset = atoi(val);
				++state;
				break;
			case 6:
				temp_dat.y_offset = atoi(val);
				++state;
				break;
			case 7:
				temp_dat.x_advance = atoi(val);
				++state;
				break;
			default:
				break;
			}
		}
		else if (temp == '\n')
		{
			state = 0;
			data[id] = temp_dat;
		}
	}
	return true;
}