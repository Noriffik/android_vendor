
%defs = ();

open OUTPUT, "+>$ARGV[1]";
print OUTPUT "//\n";
print OUTPUT "// This file is autogenerated by simplify_memmap.pl\n";
print OUTPUT "//\n";
Simplify($ARGV[0]);


sub Simplify {
  print "$_[0]";
  open my $INPUT, "$_[0]" or die "Could not open file '$_[0]'";
	while (<$INPUT>) {
		$line = "$_";
		if ($line =~ /^#include\s+"([^"]+)/) {
		  print OUTPUT "// $line";
		  Simplify($ARGV[2].$1);
		  next;
		  }
		if ($line =~ /^(#define\s+)(\w+)(\s+)(.+)$/) {
		$pre_lhs = $1;
		$lhs = $2;
		$post_lhs = $3;
		$rhs = $4;
		foreach $k (keys %defs) {
			$rhs =~ s/$k/$defs{"$k"}/g;
		}
		$rhs_val = eval($rhs);
		if ($rhs_val =~ /^\d+$/) {
			printf OUTPUT "%s0x%08x\n", "$pre_lhs$lhs$post_lhs", $rhs_val;
			$defs{"$lhs"} = $rhs_val;
		}
		else {
			printf OUTPUT "$line";
			$defs{"$lhs"} = $rhs;
		}
		}
		else {
			print OUTPUT "$line";
		}
	}
  close $INPUT;
}

exit 0;