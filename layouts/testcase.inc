###
###
#
###
###

Counter testcaseCnt
LabelString          "Test Case: \arabic{testcaseCnt}."
PrettyFormat         "Test Case: ##"
End

Counter subtestcaseCnt
Within               testcaseCnt
LabelString          "Sub Test Case: \arabic{subtestcaseCnt}."
PrettyFormat         "Sub Test Case: ##"
End

Counter subsubtestcaseCnt
Within               subtestcaseCnt
LabelString          "Sub Sub Test Case: \arabic{subsubtestcaseCnt}."
PrettyFormat         "Sub Sub Test Case: ##"
End

Counter subsubsubtestcaseCnt
Within               subsubtestcaseCnt
LabelString          "Sub Sub Sub Test Case: \arabic{subsubtestcaseCnt}."
PrettyFormat         "Sub Sub Sub Test Case: ##"
End

Style TestList
      Category              Test
      KeepEmpty             1
      Margin                Dynamic
      LatexType             Command
      LatexName             listoftestcase
      ParIndent             MM
      Align                 Block
      AlignPossible         Block
      LabelType             Static
      LabelString           "--- Test Case List ---"
      LabelFont
        Size                Normal
        Color               Blue
      EndFont
End

AddToPreamble
%%%
% Preamble
%%%
\usepackage{tocloft}
\usepackage{ifthen}
\usepackage{nameref}%
\usepackage{hyperref}%
\usepackage{refstyle}%
\newcommand{\listtestcasename}{List of Test Cases}

\newref{test}{ %
refcmd = {\ref{#1}: \nameref{#1}},
name = {Test Case~},
names = {Test Case~},
Name = {Test Case~},
Names = {Test Case~},
rngtxt = \RSrngtxt,
lsttxt = \RSlsttxt
}

%%%
% EndPreamble
%%%
EndPreamble

Style Test1
Category              Test
RefPrefix test
LatexType Command
LatexName testcase
LabelType Counter
LabelCounter          testcaseCnt
LabelString           "Test Case \arabic{testcaseCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistof{testcase}{test}{\listtestcasename}
\makeatletter
\newcommand{\testcase}[1]{%
 \def\@currentlabelname{#1}%
 \refstepcounter{testcase}
 \par\noindent\textbf{Test Case \thetestcase: #1}
 \addcontentsline{test}{testcase}{\protect\numberline{\thetestcase}#1}\par}

\setcounter{testdepth}{1}
\makeatother
EndPreamble
End

Style Test2
Category              Test
RefPrefix test
LatexType Command
LatexName subtestcase
LabelType Counter

LabelCounter          subtestcaseCnt
LabelString           "Test Case \arabic{testcaseCnt}.\arabic{subtestcaseCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistentry[testcase]{subtestcase}{test}{1}
\makeatletter
\newcommand{\subtestcase}[1]{%
 \def\@currentlabelname{#1}%
 \refstepcounter{subtestcase}
 \par\noindent\textbf{Test Case \thesubtestcase: #1}
 \addcontentsline{test}{subtestcase}{\protect\numberline{\thesubtestcase}#1}}

\setcounter{testdepth}{2}
\makeatother
EndPreamble
End


Style Test3
Category              Test
RefPrefix test
LatexType Command
LatexName subsubtestcase
LabelType Counter

LabelCounter          subsubtestcaseCnt
LabelString           "Test Case \arabic{testcaseCnt}.\arabic{subtestcaseCnt}.\arabic{subsubtestcaseCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistentry[subtestcase]{subsubtestcase}{test}{1}
\makeatletter
\newcommand{\subsubtestcase}[1]{%
 \def\@currentlabelname{#1}%
 \refstepcounter{subsubtestcase}
 \par\noindent\textbf{Test Case \thesubsubtestcase: #1}
 \addcontentsline{test}{subsubtestcase}{\protect\numberline{\thesubsubtestcase}#1}}

\setcounter{testdepth}{3}
\makeatother
EndPreamble
End

Style Test4
Category              Test
RefPrefix test
LatexType Command
LatexName subsubsubtestcase
LabelType Counter

LabelCounter          subsubsubtestcaseCnt
LabelString           "Test Case \arabic{testcaseCnt}.\arabic{subtestcaseCnt}.\arabic{subsubtestcaseCnt}.\arabic{subsubsubtestcaseCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistentry[subsubtestcase]{subsubsubtestcase}{test}{1}
\cftsetindents{subsubsubtestcase}{1.5em}{3.0em}
\makeatletter
\newcommand{\subsubsubtestcase}[1]{%
 \def\@currentlabelname{#1}%
 \refstepcounter{subsubsubtestcase}
 \par\noindent\textbf{Test Case \thesubsubsubtestcase: #1}
 \addcontentsline{test}{subsubsubtestcase}{\protect\numberline{\thesubsubsubtestcase}#1}}

\setcounter{testdepth}{4}
\makeatother
EndPreamble
End


###
###
#
###
###
