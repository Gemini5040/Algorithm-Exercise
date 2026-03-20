/*

文件组织结构：
├── main.exe       (你的程序)
├── brute.exe      (暴力程序/标程)
├── testdata/      (测试数据目录)
│   ├── test1.in
│   ├── test2.in
│   └── ...
└── compare.exe    (对拍程序)

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <windows.h> // 用于目录遍历

using namespace std;

// 带行号输出差异内容
void outputDiffWithLineNumbers(const string& file1Content, const string& file2Content,
	const vector<string>& file1Lines, const vector<string>& file2Lines) {
		cout << "\n差异详情:" << endl;
		cout << "----------------------------" << endl;
		
		for (size_t i = 0; i < max(file1Lines.size(), file2Lines.size()); ++i) {
			string line1 = (i < file1Lines.size()) ? file1Lines[i] : "(文件结束)";
			string line2 = (i < file2Lines.size()) ? file2Lines[i] : "(文件结束)";
			
			if (line1 != line2) {
				cout << "行 " << (i+1) << ":\n";
				cout << "主程序: " << line1 << "\n";
				cout << "暴力程序: " << line2 << "\n";
				cout << "----------------------------" << endl;
			}
		}
	}

// 比较两个文件内容是否相同并输出差异
bool compareFilesWithDiff(const string& file1, const string& file2) {
	ifstream f1(file1), f2(file2);
	vector<string> lines1, lines2;
	string line;
	
	while (getline(f1, line)) lines1.push_back(line);
	while (getline(f2, line)) lines2.push_back(line);
	
	// 如果行数不同或有差异
	if (lines1.size() != lines2.size() || !equal(lines1.begin(), lines1.end(), lines2.begin())) {
		outputDiffWithLineNumbers(file1, file2, lines1, lines2);
		return false;
	}
	
	return true;
}

int main() {
	// 确保输出目录存在
	system("mkdir output 2> nul");
	
	WIN32_FIND_DATA findData;
	HANDLE hFind = FindFirstFile(".\\testdata\\*.in", &findData);
	
	if (hFind == INVALID_HANDLE_VALUE) {
		cerr << "未找到测试数据。请创建testdata目录并将.in文件放入其中。" << endl;
		return 1;
	}
	
	int passed = 0, failed = 0;
	
	do {
		string inFile = ".\\testdata\\" + string(findData.cFileName);
		string testName = string(findData.cFileName).substr(0, string(findData.cFileName).find('.'));
		
		cout << "===================== 测试用例: " << testName << " =====================" << endl;
		
		// 运行主程序
		string mainCmd = "main.exe < " + inFile + " > output\\" + testName + "_main.out 2>&1";
		int mainRet = system(mainCmd.c_str());
		if (mainRet != 0) {
			cerr << "主程序运行时出错(返回值 " << mainRet << ")" << endl;
			failed++;
			continue;
		}
		
		// 运行暴力程序
		string bruteCmd = "brute.exe < " + inFile + " > output\\" + testName + "_brute.out 2>&1";
		int bruteRet = system(bruteCmd.c_str());
		if (bruteRet != 0) {
			cerr << "暴力程序运行时出错(返回值 " << bruteRet << ")" << endl;
			failed++;
			continue;
		}
		
		// 比较输出
		string mainOutput = "output\\" + testName + "_main.out";
		string bruteOutput = "output\\" + testName + "_brute.out";
		
		if (compareFilesWithDiff(mainOutput, bruteOutput)) {
			cout << "测试通过!" << endl;
			passed++;
		} else {
			cerr << "===================== 输出不一致 =====================" << endl;
			cerr << "输入文件: " << inFile << endl;
			cerr << "主程序输出: " << mainOutput << endl;
			cerr << "暴力程序输出: " << bruteOutput << endl;
			cerr << "======================================================" << endl;
			failed++;
		}
		
	} while (FindNextFile(hFind, &findData));
	
	FindClose(hFind);
	
	cout << "\n测试总结: =====================" << endl;
	cout << "通过测试: " << passed << endl;
	cout << "失败测试: " << failed << endl;
	cout << "总测试用例: " << (passed + failed) << endl;
	
	if (failed == 0) {
		cout << "所有测试通过！恭喜！" << endl;
	} else {
		cout << "有" << failed << "个测试未通过，请检查输出差异" << endl;
	}
	
	return 0;
}
