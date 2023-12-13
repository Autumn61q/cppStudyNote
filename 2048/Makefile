# Makefile

# 设置编译器
CXX = g++
# 设置Qt安装目录
QTDIR = D:\Qt\6.6.1
# 设置Qt包含目录
INCDIR = $(QTDIR)/include
# 设置Qt库目录
LIBDIR = $(QTDIR)/lib
# 设置Qt库
LIBS = -lQt5Core -lQt5Widgets

# 设置编译选项
CXXFLAGS = -std=c++11 -I$(INCDIR)

# 生成gui.exe
gui.exe: maingui.cpp mainwindowgui.cpp mainwindow.h
	$(CXX) $(CXXFLAGS) -L$(LIBDIR) -o gui.exe maingui.cpp mainwindowgui.cpp $(LIBS)

# # 生成cli.exe
# cli.exe: maincli.cpp mainwindowCLI.cpp mainwindow.h
# 	$(CXX) $(CXXFLAGS) -o cli.exe maincli.cpp mainwindowCLI.cpp

# 清理生成的文件
clean:
	rm -f gui.exe cli.exe
