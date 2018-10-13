function Initialize()
	BassMax = 0
	TrebMax = 0
	TrebAvg = 0
	Bass = 0
	Treb = 0
	BassFloor = 0
	TrebFloor = 0
	BassOut = 0
	TrebOut = 0
	BassMaxDec = 0
	TrebMaxDec = 0
	
	MeasureRaw0 = SKIN:GetMeasure('MeasureAudioRaw0')
	MeasureRaw1 = SKIN:GetMeasure('MeasureAudioRaw1')
	MeasureRaw2 = SKIN:GetMeasure('MeasureAudioRaw2')
	MeasureRaw3 = SKIN:GetMeasure('MeasureAudioRaw3')
	MeasureRaw4 = SKIN:GetMeasure('MeasureAudioRaw4')
	MeasureRaw5 = SKIN:GetMeasure('MeasureAudioRaw5')
	MeasureRaw6 = SKIN:GetMeasure('MeasureAudioRaw6')
	MeasureRaw7 = SKIN:GetMeasure('MeasureAudioRaw7')
	MeasureRaw8 = SKIN:GetMeasure('MeasureAudioRaw8')
	MeasureRaw9 = SKIN:GetMeasure('MeasureAudioRaw9')
	MeasureRaw10 = SKIN:GetMeasure('MeasureAudioRaw10')
	MeasureRaw11 = SKIN:GetMeasure('MeasureAudioRaw11')
end

function Update()
	local A0 = MeasureRaw0:GetValue()
	local A1 = MeasureRaw1:GetValue()
	local A2 = MeasureRaw2:GetValue()
	local A3 = MeasureRaw3:GetValue()
	local A4 = MeasureRaw4:GetValue()
	local A5 = MeasureRaw5:GetValue()
	local A6 = MeasureRaw6:GetValue()
	local A7 = MeasureRaw7:GetValue()
	local A8 = MeasureRaw8:GetValue()
	local A9 = MeasureRaw9:GetValue()
	local A10 = MeasureRaw10:GetValue()
	local A11 = MeasureRaw11:GetValue()
	
	-- Process Bass
	local BassVal = math.max(A0, A1, A2, A3, A4)
	
	if BassVal > 0.8 * BassMax then
		BassOut = 1
		BassMaxDec = 0.01
	else
		BassOut = BassOut - 0.15;
		BassOut = math.max(BassOut, 0)
	end
	
	BassMax = BassMax - BassMaxDec;
	BassMax = math.max(BassMax, BassVal)
	BassMax = math.max(BassMax, 0.05)
	BassMaxDec = BassMaxDec + 0.0001
	
	-- Process Treble
	local TrebVal = math.max(A5, A6, A7, A8, A9, A10, A11)
	
	if TrebVal > 0.8 * TrebMax then
		TrebOut = 1
		TrebMaxDec = 0.01
	else
		TrebOut = TrebOut - 0.15;
		TrebOut = math.max(TrebOut, 0)
	end
	
	TrebMax = TrebMax - TrebMaxDec;
	TrebMax = math.max(TrebMax, TrebVal)
	TrebMax = math.max(TrebMax, 0.05)
	TrebMaxDec = TrebMaxDec + 0.0001
	
	-- Send values through web socket
	local msg = "!CommandMeasure MeasureWS B" .. math.floor(BassOut*1023) .. ";T" .. math.floor(TrebOut*1023)
	SKIN:Bang(msg)
	
	return 0
end
