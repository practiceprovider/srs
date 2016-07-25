###
###
#
###
###

Counter requirementCnt
LabelString          "Requirement: \arabic{requirementCnt}."
PrettyFormat         "Requirement: ##"
End

Counter subrequirementCnt
Within               requirementCnt
LabelString          "Requirement: \arabic{subrequirementCnt}."
PrettyFormat         "Requirement: ##"
End

Counter subsubrequirementCnt
Within               subrequirementCnt
LabelString          "Sub Sub Requirement: \arabic{subsubrequirementCnt}."
PrettyFormat         "Sub Sub Requirement: ##"
End

Counter subsubsubrequirementCnt
Within               subsubrequirementCnt
LabelString          "Sub Sub Sub Requirement: \arabic{subsubrequirementCnt}."
PrettyFormat         "Sub Sub Sub Requirement: ##"
End

Style RequirementList
      Category              Requirement
      KeepEmpty             1
      Margin                Dynamic
      LatexType             Command
      LatexName             listofrequirement
      ParIndent             MM
      Align                 Block
      AlignPossible         Block
      LabelType             Static
      LabelString           "--- Requirement List ---"
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
\newcommand{\listrequirementname}{List of Requirements}

\newref{rqmt}{ %
refcmd = {\ref{#1}: \nameref{#1}},
name = {Requirement~},
names = {Requirement~},
Name = {Requirement~},
Names = {Requirement~},
rngtxt = \RSrngtxt,
lsttxt = \RSlsttxt
}

%%%
% EndPreamble
%%%
EndPreamble

Style Requirement1
Category              Requirement
RefPrefix rqmt
LatexType Command
LatexName requirement
LabelType Counter
LabelCounter          requirementCnt
LabelString           "Requirement \arabic{requirementCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistof{requirement}{rqmt}{\listrequirementname}
\makeatletter
\newcommand{\requirement}[1]{%
 \def\@currentlabelname{#1}%
 \refstepcounter{requirement}
 \par\noindent\textbf{Requirement \therequirement: #1}
 \addcontentsline{rqmt}{requirement}{\protect\numberline{\therequirement}#1}\par}

\setcounter{rqmtdepth}{1}
\makeatother
EndPreamble
End

Style Requirement2
Category              Requirement
RefPrefix rqmt
LatexType Command
LatexName subrequirement
LabelType Counter

LabelCounter          subrequirementCnt
LabelString           "Requirement \arabic{requirementCnt}.\arabic{subrequirementCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistentry[requirement]{subrequirement}{rqmt}{1}
\makeatletter
\newcommand{\subrequirement}[1]{%
 \def\@currentlabelname{#1}%
 \refstepcounter{subrequirement}
 \par\noindent\textbf{Requirement \thesubrequirement: #1}
 \addcontentsline{rqmt}{subrequirement}{\protect\numberline{\thesubrequirement}#1}}

\setcounter{rqmtdepth}{2}
\makeatother
EndPreamble
End


Style Requirement3
Category              Requirement
RefPrefix rqmt
LatexType Command
LatexName subsubrequirement
LabelType Counter

LabelCounter          subsubrequirementCnt
LabelString           "Requirement \arabic{requirementCnt}.\arabic{subrequirementCnt}.\arabic{subsubrequirementCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistentry[subrequirement]{subsubrequirement}{rqmt}{1}
\makeatletter
\newcommand{\subsubrequirement}[1]{%
 \def\@currentlabelname{#1}%
 \refstepcounter{subsubrequirement}
 \par\noindent\textbf{Requirement \thesubsubrequirement: #1}
 \addcontentsline{rqmt}{subsubrequirement}{\protect\numberline{\thesubsubrequirement}#1}}

\setcounter{rqmtdepth}{3}
\makeatother
EndPreamble
End

Style Requirement4
Category              Requirement
RefPrefix rqmt
LatexType Command
LatexName subsubsubrequirement
LabelType Counter

LabelCounter          subsubsubrequirementCnt
LabelString           "Requirement \arabic{requirementCnt}.\arabic{subrequirementCnt}.\arabic{subsubrequirementCnt}.\arabic{subsubsubrequirementCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistentry[subsubrequirement]{subsubsubrequirement}{rqmt}{1}
\cftsetindents{subsubsubrequirement}{1.5em}{3.0em}
\makeatletter
\newcommand{\subsubsubrequirement}[1]{%
 \def\@currentlabelname{#1}%
 \refstepcounter{subsubsubrequirement}
 \par\noindent\textbf{Requirement \thesubsubsubrequirement: #1}
 \addcontentsline{rqmt}{subsubsubrequirement}{\protect\numberline{\thesubsubsubrequirement}#1}}

\setcounter{rqmtdepth}{4}
\makeatother
EndPreamble
End


###
###
#
###
###
