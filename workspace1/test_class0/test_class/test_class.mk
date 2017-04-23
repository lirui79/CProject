##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=test_class
ConfigurationName      :=Debug
WorkspacePath          := "E:\MyWork\test"
ProjectPath            := "E:\MyWork\test_class"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=stone
Date                   :=11/22/2012
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
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
ObjectsFileList        :="E:\MyWork\test_class\test_class.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/Shape$(ObjectSuffix) $(IntermediateDirectory)/Point$(ObjectSuffix) $(IntermediateDirectory)/Circle$(ObjectSuffix) $(IntermediateDirectory)/IMethod$(ObjectSuffix) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects) > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.c $(IntermediateDirectory)/main$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/MyWork/test_class/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "E:/MyWork/test_class/main.c"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "E:/MyWork/test_class/main.c"

$(IntermediateDirectory)/Shape$(ObjectSuffix): Shape.c $(IntermediateDirectory)/Shape$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/MyWork/test_class/Shape.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Shape$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Shape$(DependSuffix): Shape.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Shape$(ObjectSuffix) -MF$(IntermediateDirectory)/Shape$(DependSuffix) -MM "E:/MyWork/test_class/Shape.c"

$(IntermediateDirectory)/Shape$(PreprocessSuffix): Shape.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Shape$(PreprocessSuffix) "E:/MyWork/test_class/Shape.c"

$(IntermediateDirectory)/Point$(ObjectSuffix): Point.c $(IntermediateDirectory)/Point$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/MyWork/test_class/Point.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Point$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Point$(DependSuffix): Point.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Point$(ObjectSuffix) -MF$(IntermediateDirectory)/Point$(DependSuffix) -MM "E:/MyWork/test_class/Point.c"

$(IntermediateDirectory)/Point$(PreprocessSuffix): Point.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Point$(PreprocessSuffix) "E:/MyWork/test_class/Point.c"

$(IntermediateDirectory)/Circle$(ObjectSuffix): Circle.c $(IntermediateDirectory)/Circle$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/MyWork/test_class/Circle.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Circle$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Circle$(DependSuffix): Circle.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Circle$(ObjectSuffix) -MF$(IntermediateDirectory)/Circle$(DependSuffix) -MM "E:/MyWork/test_class/Circle.c"

$(IntermediateDirectory)/Circle$(PreprocessSuffix): Circle.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Circle$(PreprocessSuffix) "E:/MyWork/test_class/Circle.c"

$(IntermediateDirectory)/IMethod$(ObjectSuffix): IMethod.c $(IntermediateDirectory)/IMethod$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/MyWork/test_class/IMethod.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IMethod$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IMethod$(DependSuffix): IMethod.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IMethod$(ObjectSuffix) -MF$(IntermediateDirectory)/IMethod$(DependSuffix) -MM "E:/MyWork/test_class/IMethod.c"

$(IntermediateDirectory)/IMethod$(PreprocessSuffix): IMethod.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IMethod$(PreprocessSuffix) "E:/MyWork/test_class/IMethod.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Shape$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Shape$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Shape$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Point$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Point$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Point$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Circle$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Circle$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Circle$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/IMethod$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/IMethod$(DependSuffix)
	$(RM) $(IntermediateDirectory)/IMethod$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "E:\MyWork\test\.build-debug\test_class"


