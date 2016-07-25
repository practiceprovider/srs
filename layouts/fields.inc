###
###
#
###
###

Counter fieldCnt
LabelString          "Field: \arabic{fieldCnt}."
PrettyFormat         "Field: ##"
End

Counter subfieldCnt
Within               fieldCnt
LabelString          "Field: \arabic{subfieldCnt}."
PrettyFormat         "Field: ##"
End

Counter subsubfieldCnt
Within               subfieldCnt
LabelString          "Sub Sub Field: \arabic{subsubfieldCnt}."
PrettyFormat         "Sub Sub Field: ##"
End

Counter subsubsubfieldCnt
Within               subsubfieldCnt
LabelString          "Sub Sub Sub Field: \arabic{subsubfieldCnt}."
PrettyFormat         "Sub Sub Sub Field: ##"
End

Style FieldList
      Category              Field
      KeepEmpty             1
      Margin                Dynamic
      LatexType             Command
      LatexName             listoffield
      ParIndent             MM
      Align                 Block
      AlignPossible         Block
      LabelType             Static
      LabelString           "--- Field List ---"
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
\newcommand{\listfieldname}{List of Fields}

\newref{field}{ %
refcmd = {\ref{#1}: \nameref{#1}},
name = {Field~},
names = {Field~},
Name = {Field~},
Names = {Field~},
rngtxt = \RSrngtxt,
lsttxt = \RSlsttxt
}

%%%
% EndPreamble
%%%
EndPreamble

Style Field1
Category              Field
RefPrefix field
LatexType Command
LatexName field
LabelType Counter
LabelCounter          fieldCnt
LabelString           "F\arabic{fieldCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistof{field}{field}{\listfieldname}
\makeatletter
\newcommand{\field}[1]{%
 \def\@currentlabelname{#1}%
 \refstepcounter{field}
 \par\noindent\textbf{F\thefield: #1}
 \addcontentsline{field}{field}{\protect\numberline{\thefield}#1}\par}

\setcounter{fielddepth}{1}
\makeatother
EndPreamble
End

Style Field2
Category              Field
RefPrefix field
LatexType Command
LatexName subfield
LabelType Counter

LabelCounter          subfieldCnt
LabelString           "F\arabic{fieldCnt}.\arabic{subfieldCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistentry[field]{subfield}{field}{1}
\makeatletter
\newcommand{\subfield}[1]{%
 \def\@currentlabelname{#1}%
 \refstepcounter{subfield}
 \par\noindent\textbf{Field \thesubfield: #1}
 \addcontentsline{field}{subfield}{\protect\numberline{\thesubfield}#1}}

\setcounter{fielddepth}{2}
\makeatother
EndPreamble
End


Style Field3
Category              Field
RefPrefix field
LatexType Command
LatexName subsubfield
LabelType Counter

LabelCounter          subsubfieldCnt
LabelString           "F\arabic{fieldCnt}.\arabic{subfieldCnt}.\arabic{subsubfieldCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistentry[subfield]{subsubfield}{field}{1}
\makeatletter
\newcommand{\subsubfield}[1]{%
 \def\@currentlabelname{#1}%
 \refstepcounter{subsubfield}
 \par\noindent\textbf{Field \thesubsubfield: #1}
 \addcontentsline{field}{subsubfield}{\protect\numberline{\thesubsubfield}#1}}

\setcounter{fielddepth}{3}
\makeatother
EndPreamble
End

Style Field4
Category              Field
RefPrefix field
LatexType Command
LatexName subsubsubfield
LabelType Counter

LabelCounter          subsubsubfieldCnt
LabelString           "F\arabic{fieldCnt}.\arabic{subfieldCnt}.\arabic{subsubfieldCnt}.\arabic{subsubsubfieldCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistentry[subsubfield]{subsubsubfield}{field}{1}
\cftsetindents{subsubsubfield}{1.5em}{3.0em}
\makeatletter
\newcommand{\subsubsubfield}[1]{%
 \def\@currentlabelname{#1}%
 \refstepcounter{subsubsubfield}
 \par\noindent\textbf{Field \thesubsubsubfield: #1}
 \addcontentsline{field}{subsubsubfield}{\protect\numberline{\thesubsubsubfield}#1}}

\setcounter{fielddepth}{4}
\makeatother
EndPreamble
End


###
###
#
###
###
