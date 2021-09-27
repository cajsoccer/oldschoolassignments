##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=COP3502P5
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Carter/Desktop/cpp/Section4
ProjectPath            :=C:/Users/Carter/Desktop/cpp/Section4/COP3502P5
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Carter
Date                   :=08/02/2021
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="COP3502P5.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  -static
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++17 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Dictionary.cpp$(ObjectSuffix) $(IntermediateDirectory)/Grader.cpp$(ObjectSuffix) $(IntermediateDirectory)/Student.cpp$(ObjectSuffix) $(IntermediateDirectory)/GraduateStudent.cpp$(ObjectSuffix) $(IntermediateDirectory)/UndergraduateStudent.cpp$(ObjectSuffix) $(IntermediateDirectory)/HighSchoolStudent.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(ConfigurationName)"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(ConfigurationName)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Carter/Desktop/cpp/Section4/COP3502P5/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Dictionary.cpp$(ObjectSuffix): Dictionary.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Dictionary.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Dictionary.cpp$(DependSuffix) -MM Dictionary.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Carter/Desktop/cpp/Section4/COP3502P5/Dictionary.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Dictionary.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Dictionary.cpp$(PreprocessSuffix): Dictionary.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Dictionary.cpp$(PreprocessSuffix) Dictionary.cpp

$(IntermediateDirectory)/Grader.cpp$(ObjectSuffix): Grader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Grader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Grader.cpp$(DependSuffix) -MM Grader.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Carter/Desktop/cpp/Section4/COP3502P5/Grader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Grader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Grader.cpp$(PreprocessSuffix): Grader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Grader.cpp$(PreprocessSuffix) Grader.cpp

$(IntermediateDirectory)/Student.cpp$(ObjectSuffix): Student.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Student.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Student.cpp$(DependSuffix) -MM Student.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Carter/Desktop/cpp/Section4/COP3502P5/Student.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Student.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Student.cpp$(PreprocessSuffix): Student.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Student.cpp$(PreprocessSuffix) Student.cpp

$(IntermediateDirectory)/GraduateStudent.cpp$(ObjectSuffix): GraduateStudent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GraduateStudent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GraduateStudent.cpp$(DependSuffix) -MM GraduateStudent.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Carter/Desktop/cpp/Section4/COP3502P5/GraduateStudent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GraduateStudent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GraduateStudent.cpp$(PreprocessSuffix): GraduateStudent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GraduateStudent.cpp$(PreprocessSuffix) GraduateStudent.cpp

$(IntermediateDirectory)/UndergraduateStudent.cpp$(ObjectSuffix): UndergraduateStudent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/UndergraduateStudent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/UndergraduateStudent.cpp$(DependSuffix) -MM UndergraduateStudent.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Carter/Desktop/cpp/Section4/COP3502P5/UndergraduateStudent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/UndergraduateStudent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/UndergraduateStudent.cpp$(PreprocessSuffix): UndergraduateStudent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/UndergraduateStudent.cpp$(PreprocessSuffix) UndergraduateStudent.cpp

$(IntermediateDirectory)/HighSchoolStudent.cpp$(ObjectSuffix): HighSchoolStudent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/HighSchoolStudent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/HighSchoolStudent.cpp$(DependSuffix) -MM HighSchoolStudent.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Carter/Desktop/cpp/Section4/COP3502P5/HighSchoolStudent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/HighSchoolStudent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/HighSchoolStudent.cpp$(PreprocessSuffix): HighSchoolStudent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/HighSchoolStudent.cpp$(PreprocessSuffix) HighSchoolStudent.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


