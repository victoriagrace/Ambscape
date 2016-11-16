import("stdfaust.lib");
import("oscillator.lib");
import("filter.lib");

freq=nentry("freq",440,12,10000,0.01) :si.smoo;
fc_lp=nentry("fc_lp",500,12, 3000,0.01) :si.smoo;
fc_hp=nentry("fc_hp",500,12, 3000,0.01) :si.smoo;

gain = nentry("gain",1,0,1,0.01) :si.smoo;


//process = hgroup("saw",saw2(freq):resonlp(fc_lp, 8, 1):resonhp(fc_hp, 8, 1));
process = hgroup("saw",gain*saw2(freq):resonlp(fc_lp, 8, 1));




